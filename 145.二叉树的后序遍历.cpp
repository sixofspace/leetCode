/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 */
#include <vector>
#include <stack>
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
    // 常规递归求解
    // vector<int> res;
    // void test(TreeNode* root){
    //     if (!root)
    //     {
    //         return ;
    //     }
    //     test(root->left);
    //     test(root->right);
    //     res.push_back(root->val);
    // }
    // vector<int> postorderTraversal(TreeNode* root) {
    //     test(root);
    //     return res;
    // }
 
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root)
        {
            return res;
        }
        stack<TreeNode*> st;
        TreeNode* prev = nullptr;
        while (!st.empty() || root)
        {
            while (root)
            {
                st.emplace(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            if ( root->right == nullptr || root->right == prev)
            {
                res.push_back(root->val);
                prev = root;
                root = nullptr;
            }else{
                st.emplace(root);
                root = root->right;
            }
        }
        return res;
    }
};
// @lc code=end

