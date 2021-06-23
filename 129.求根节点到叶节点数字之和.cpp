/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
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

// s深度遍历和广度遍历
    vector<int> res;
    int pathSum = 0;
    void testback(vector<int> &res ,int pathSum ,TreeNode* root ){
        if (!root)
        {
            return;
        }
        pathSum = pathSum*10 + root->val;
        if (root->left == nullptr && root->right == nullptr)
        {
             res.push_back(pathSum);
        }
        testback(res,pathSum,root->left);
        testback(res,pathSum,root->right);
        pathSum = (pathSum - root->val)/10;

    }
    int sumNumbers(TreeNode* root) {
        testback(res,pathSum,root);
        int sumnumber = 0;
        for (int & s:res)
        {
            sumnumber += s;
        }
        
        return sumnumber;
    }
};
// @lc code=end

