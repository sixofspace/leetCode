/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (!root)
        {
            return ret;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int currentSize = q.size();
            vector<int> tempCur;
            for (int i = 0; i < currentSize; i++)
            {
                auto tempNode = q.front();
                q.pop();
                if (tempNode->left != nullptr)
                {
                    q.push(tempNode->left);
                }
                if (tempNode->right != nullptr)
                {
                    q.push(tempNode->right);
                }
                tempCur.push_back(tempNode->val);
            }
            ret.push_back(tempCur);
        }
        return ret;
    }
};
// @lc code=end

