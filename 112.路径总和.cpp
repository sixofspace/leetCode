/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
 */
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
struct TreeNode
{
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
  
    bool hasPathSum(TreeNode* root, int targetSum) {

        //递归 可以使用或者 来判定有一个正确值时返回 ， 递归时注意每个条件都需要返回递归
        if(!root){
            return false;
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            return targetSum == root->val;
        }
        return hasPathSum(root->left , targetSum - root->val) || hasPathSum(root->right , targetSum - root->val);
    }
};
// @lc code=end

