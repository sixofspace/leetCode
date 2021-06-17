/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    // 自顶向下的递归
    // int maxheigh(TreeNode* root){
    //     if (!root)
    //     {
    //        return 0 ;
    //     }
    //     return max(maxheigh(root->left) +1 ,maxheigh(root->right) + 1 );
    // }
    // bool isBalanced(TreeNode* root) {
    //     //递归注意 真值返回
    //     if (!root)
    //     {
    //         return true;
    //     }

    //     int t1 = abs(maxheigh(root->left) - maxheigh(root->right));
    //     if (t1 > 1)
    //     {
    //         return false;
    //     }
    //     return isBalanced(root->left) && isBalanced(root->right) ;
    // }
    // 自底向上的递归
    // 因此对于同一个节点，函数 height 会被重复调用，导致时间复杂度较高。
    // 如果使用自底向上的做法，则对于每个节点，函数 height 只会被调用一次。
    // 自底向上递归的做法类似于后序遍历，对于当前遍历到的节点，先递归地判断其左右子树是否平衡，
    // 再判断以当前节点为根的子树是否平衡。如果一棵子树是平衡的，则返回其高度（高度一定是非负整数），
    // 否则返回 -1。如果存在一棵子树不平衡，则整个二叉树一定不平衡。

    int heigh(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        int leftHeight = heigh(root->left);
        int rightHeight = heigh(root->right);
        if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1)
        {
            return -1;
        }
        else
        {
            return max(leftHeight, rightHeight) + 1;
        }
    }
    bool isBalanced(TreeNode *root)
    {
        return heigh(root) >= 0;
    }
};
// @lc code=end
