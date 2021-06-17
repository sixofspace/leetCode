// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem111.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode* root) {
        // 深度优先搜索
        // if (root && root->left == nullptr && root->right == nullptr)
        // {
        //     return 1;
        // }else if (!root )
        // {
        //     return 0;
        // }else if (root->left == nullptr )
        // {
        //     return minDepth(root->right) + 1;
        // }else if (root->right == nullptr)
        // {
        //     return minDepth(root->left) + 1;
        // }
        
        // return min(minDepth(root->left) ,minDepth(root->right) ) + 1;
        
        //广度优先遍历

        if (!root)
        {
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0 ; 
        while (!q.empty())
        {
            int currentSize = q.size();
            for (int i = 0; i < currentSize; i++)
            {
                depth++;
                TreeNode* tmpNode = q.front();
                q.pop();
                if (tmpNode->left == nullptr && tmpNode->right == nullptr)
                {
                    return depth;
                }
                if (tmpNode->left != nullptr)
                {
                    q.push(tmpNode->left);
                }
                if (tmpNode->right != nullptr)
                {
                    q.push(tmpNode->right);
                }               
            }
            
        }
        
        return 0;
    }
};
// @lc code=end

