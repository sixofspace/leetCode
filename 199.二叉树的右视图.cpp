/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode* root) {
        // 层序遍历 找出最后一个就行了  
        // 也可以使用深度优先遍历
        vector<int> res;
        queue<TreeNode*> q;
        if (!root)
        {
            return res;
        }
        q.push(root);
        while (!q.empty())
        {
            int currentSize = q.size();
            for (int i = 0; i < currentSize; i++)
            {
                TreeNode* tmp = q.front();
                q.pop();
                if (tmp->left != nullptr)
                {
                   q.push(tmp->left);
                }
                if (tmp->right != nullptr)
                {
                   q.push(tmp->right);
                }
                if ( i == currentSize - 1)
                {
                    res.push_back(tmp->val);
                }
            }
        }
        return res;        

    }
};
// @lc code=end

