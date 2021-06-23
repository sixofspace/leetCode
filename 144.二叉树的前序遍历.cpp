// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem144.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */
// #include <vector>
// #include <stack>
// #include <iostream>
// using namespace std;
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
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
    //     res.push_back(root->val);
    //     test(root->left);
    //     test(root->right);
    // }
    // vector<int> preorderTraversal(TreeNode* root) {
    //     test(root);
    //     return res;
    // }
    vector<int> preorderTraversal(TreeNode* root) {
    //使用迭代求解
        vector<int> res;
        if (!root)
        {
            return res;
        }
        stack<TreeNode*> st;
        while (!st.empty() || root != nullptr )
        {
            while (root != nullptr)
            {
               res.push_back(root->val);
               st.emplace(root);
               root = root->left;
            }
            root = st.top();
            st.pop();
            root = root->right;
        }
        return res;

    }
};
// @lc code=end

