// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem103.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
 */
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
//  struct TreeNode {
//      int val;
//      TreeNode *left;
//      TreeNode *right;
//      TreeNode() : val(0), left(nullptr), right(nullptr) {}
//      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//   };
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        // 层序遍历的变种 
        // 使用双端队列存储 中间层数的顺序
        vector<vector<int>> ret;
        if (!root)
        {
            return ret;
        }
        // queue<TreeNode*> q;
        deque<TreeNode *> q;
        q.push_front(root);
        int flag = true;
        while (!q.empty())
        {
            int currentSize = q.size();
            vector<int> tempCur;
            deque<int> tmp;
            for (int i = 0; i < currentSize; i++)
            {
                
                auto *tempNode = q.front();
                q.pop_front();
                if (flag)
                {
                    tmp.push_back(tempNode->val);
                }
                else
                {
                    tmp.push_front(tempNode->val);
                }
                if (tempNode->left != nullptr)
                {
                    q.push_back(tempNode->left);
                }
                if (tempNode->right != nullptr)
                {
                    q.push_back(tempNode->right);
                }
                
            }
            flag = !flag;
            ret.push_back(vector<int>{tmp.begin(),tmp.end()});
        }
        return ret;
    }
};
// @lc code=end
