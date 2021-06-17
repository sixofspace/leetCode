/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode* test(vector<int>& nums, int left , int right){
        if (left > right)
        {
            return nullptr;
        }
        
        int node = ceil((left + right) / 2.0) ;
        TreeNode * root = new TreeNode(nums[node]);
        root->left = test(nums, left, node - 1);
        root->right = test(nums,node + 1 , right);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {

        TreeNode* root = test(nums , 0 , nums.size() - 1);

        return root;

    }
};
// @lc code=end

