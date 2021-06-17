/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 */
#include <vector>
#include <queue>
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
    int maxheigh(TreeNode* root){
        if (!root)
        {
           return 0 ;
        }
        return max(maxheigh(root->left) +1 ,maxheigh(root->right) + 1 );
    }
    bool isBalanced(TreeNode* root) {
        int t1 = abs(maxheigh(root->left) - maxheigh(root->right));
        if (t1 > 1)
        {
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right) ;
    }
};
// @lc code=end

