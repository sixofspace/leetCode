/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
 */
#include <vector>
#include <iostream>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int start , int end){
        if (start > end)
        {
           return {nullptr};
        }
        vector<TreeNode*> allTreeNodes;

        for (int i = start; i <= end; i++)
        {
            vector<TreeNode*> leftTreeNodes = generateTrees(start , i -1 );
            vector<TreeNode*> rightTreeNodes = generateTrees( i + 1 , end);
            for(auto & left : leftTreeNodes){
                for(auto & right : rightTreeNodes){
                    TreeNode* node = new TreeNode(i);
                    node->left = left;
                    node->right = right;
                    allTreeNodes.emplace_back(node);
                }
            }

        }
        return allTreeNodes;

    }
    vector<TreeNode*> generateTrees(int n) {
        if (!n)
        {
            return {};
        }
        return generateTrees(1,n);
    }
};
// @lc code=end

