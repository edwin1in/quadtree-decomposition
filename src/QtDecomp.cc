#include "TreeNode.hpp"
#include <iostream>
#include <opencv2/opencv.hpp>

double calculate_mse(const cv::Mat& img){
    int N = img.rows * img.cols;
    double mse = 0;
    //(B,G,R,A)
    cv::Scalar mean_color = cv::mean(img);

    for(int row = 0; row < img.rows; row++){
        for(int col = 0; col < img.cols; col++){
            cv::Vec3b pixel = img.at<cv::Vec3b>(row,col);
            for(int i = 0; i < 3; i++ ){
                double diff = pixel[i] - mean_color[i];
                mse+= diff * diff;
            }
        }
    }
    return mse/(double)N;
}

std::vector<cv::Mat> split_image(const cv::Mat& img){
    int mid_row = img.rows/2;
    int mid_col = img.cols/2;

    cv::Mat nw = img(cv::Rect(0,0,mid_col,mid_row)).clone();
    cv::Mat ne = img(cv::Rect(mid_col,0,img.cols - mid_col,mid_row)).clone();
    cv::Mat sw = img(cv::Rect(0,mid_row,mid_col,img.rows-mid_row)).clone();
    cv::Mat se = img(cv::Rect(mid_col,mid_row,img.cols-mid_col,img.rows-mid_row)).clone();

    return {nw,ne,sw,se};
}

void quad_tree_decomposition(TreeNode* root, const cv::Mat& img, double threshold){
    
    if(root == nullptr){
        return;
    }

    cv::Scalar mean_color = cv::mean(img);
    root->color = cv::Vec3b(mean_color[0],mean_color[1],mean_color[2]);

    if(img.rows <= 1 || img.cols <= 1){
        return;
    }

    double mse = calculate_mse(img);

    if(mse <= threshold){
        return;
    }

    std::vector<cv::Mat> children = split_image(img);
    root->is_leaf = false;

    root->nw = new TreeNode();
    root->ne = new TreeNode();
    root->sw = new TreeNode();
    root->se = new TreeNode();

    quad_tree_decomposition(root->nw,children[0],threshold);
    quad_tree_decomposition(root->ne,children[1],threshold);
    quad_tree_decomposition(root->sw,children[2],threshold);
    quad_tree_decomposition(root->se,children[3],threshold);
    
}