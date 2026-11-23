#pragma once

#include <opencv2/core.hpp>

struct TreeNode {
    cv::Mat img;

    TreeNode* nw;
    TreeNode* ne;
    TreeNode* sw;
    TreeNode* se;

    explicit TreeNode(const cv::Mat& img) : img(img), nw(nullptr), ne(nullptr), sw(nullptr), se(nullptr) {}
};
