/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    // bool isBST(TreeNode* root , long long lower , long long upper){
    //     if (root == nullptr)
    //     {
    //         return true;
    //     }
    //     if (root->val <= lower || root->val >= upper)
    //     {
    //         return false;
    //     }
    //     return isBST(root->left , lower , root->val ) && isBST(root->right , root->val , upper );
    // }
    // bool isValidBST(TreeNode* root) {
    //     //可用递归

    //     return isBST(root,LONG_MIN , LONG_MAX);
    // }

    bool isValidBST(TreeNode* root) {
// 非递归的方法
// 中序遍历是二叉树的一种遍历方式，它先遍历左子树，再遍历根节点，最后遍历右子树。
// 而我们二叉搜索树保证了左子树的节点的值均小于根节点的值，根节点的值均小于右子树的值，因此中序遍历以后得到的序列一定是升序序列。
        long long inorder = LONG_MIN;
        stack<TreeNode*> sk;
        while ( root != nullptr || !sk.empty())
        {
            while (root != nullptr)
            {
                sk.push(root);
                root = root->left;
            }
            root = sk.top();
            if (root->val <= inorder)
            {
               return false;
            }
            sk.pop();
            inorder = root->val;
            root = root->right;
        }
        return  true;
    }
};
// @lc code=end

