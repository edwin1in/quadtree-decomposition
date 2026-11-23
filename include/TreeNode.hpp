#pragma once

#include <opencv2/core.hpp>

struct TreeNode {
    TreeNode* nw;
    TreeNode* ne;
    TreeNode* sw;
    TreeNode* se;

    cv::Vec3b color;
    bool is_leaf;

    explicit TreeNode(const cv::Vec3b& color = cv::Vec3b(0, 0, 0)) 
        :   color(color), 
            is_leaf(true), 
            nw(nullptr), 
            ne(nullptr), 
            sw(nullptr), 
            se(nullptr) 
    {}
};
