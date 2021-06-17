/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {

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
            vector<int> tmp;
            for (int i = 0; i < currentSize; i++)
            {
                auto currentNode = q.front();
                q.pop();
                if (currentNode->left != nullptr)
                {
                     q.push(currentNode->left);
                }
                if (currentNode->right != nullptr)
                {
                     q.push(currentNode->right);
                }       
                tmp.push_back(currentNode->val);
            }
            // ret.insert(ret.begin() , tmp);
            ret.push_back(tmp);
        }
        reverse(ret.begin(),ret.end());
        return ret;
        
    }
};
// @lc code=end

