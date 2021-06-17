/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
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
    bool isSame(TreeNode* p, TreeNode* q){
        //注意返回真值
        if (p == nullptr && q== nullptr)
        {
            return true;
        }
        
        if ((p == nullptr && q!= nullptr) || (p != nullptr && q == nullptr) || p->val != q->val)
        {
            return false;
        }
        return isSame(p->left,q->left) && isSame(p->right , q->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return isSame(p , q);

    }
};
// @lc code=end

