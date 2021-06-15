// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem99.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
 */
#include <vector>
#include <stack>
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
@lc code=start
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
    void recoverTree(TreeNode* root) {
        //中序遍历 注意初始化值 只关心相邻位置是否满足
        stack<TreeNode*> sk;
        TreeNode* p1 = nullptr;
        TreeNode* p2 = nullptr;
        TreeNode* pre = nullptr;
        while ( root != nullptr || !sk.empty())
        {
            while (root != nullptr)
            {
                sk.push(root);
                root = root->left;
            }
            root = sk.top();
            if (pre != nullptr &&  root->val < pre->val)
            {
               p2 = root;
               if (p1==nullptr)
               {
                   p1 = pre;
               }else{
                   break ;
               }
            }
            sk.pop();
            pre = root;
            root = root->right;
        }
        swap(p2->val , p1->val);
 
    }
};
// @lc code=end

