#include "TreeNode.hpp"
#include <iostream>
#include <opencv2/opencv.hpp>

double calculate_mse(cv::Mat img){
    int N = img.rows * img.cols;
    double mse = 0;
    //(B,G,R,A)
    cv::Scalar mean_color = cv::mean(img);

    for(int row = 0; row < img.rows; row++){
        for(int col = 0; col < img.cols; col++){
            cv::Vec3b pixel = img.at<cv::Vec3b>(row,col);
            for(int i = 0; i < 3; i++ ){
                double diff = pixel[i] - mean_color[i]
                mse+= diff * diff;
            }
        }
    }
    return mse/(double)N;
}

int main(){

    return 0;
}