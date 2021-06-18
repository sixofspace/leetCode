// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem114.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
class Solution
{
public:
    TreeNode *t = nullptr;
    // void inorder(TreeNode *tmp, TreeNode *root)
    // {
    //     if (root && tmp)
    //     {
    //         tmp->left = nullptr;
    //         tmp->right = root;
    //         inorder(tmp->right, root->left);
    //         inorder(tmp->right, root->right);
    //     }
    // }
    void flatten(TreeNode *root)
    {
        if (!root)
        {
            return;
        }
        root->right = t;
        root->left = nullptr;
        t = root;
        flatten(root->left);
        flatten(root->right);

    }
};
// @lc code=end
