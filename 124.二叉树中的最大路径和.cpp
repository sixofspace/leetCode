// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem124.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
    // 注意审题 别搞错了 不是从根节点出发
    // vector<int> res;
    // int pathSum = 0;
    // void testback(vector<int> &res,int &pathSum ,TreeNode *root){
    //     if (!root)
    //     {
    //         return;
    //     }
    //     pathSum += root->val;
    //     if (root->left == nullptr && root->right == nullptr)
    //     {
    //         res.push_back(pathSum);
    //     }
    //     testback(res,pathSum,root->left);
    //     testback(res,pathSum,root->right);
    //     pathSum -= root->val;
        
    // }
    // int maxPathSum(TreeNode *root)
    // {
    //     testback(res,pathSum,root);

    //     return *max_element(res.begin(),res.end()); 
// }

//使用递归计算当前节点的最大贡献值 ，然后将最大值路径值保存起来
    int max_sum = INT_MIN;
    int maxGain(TreeNode *root){
        if (!root)
        {
            return 0;
        }
        int leftGain = max( maxGain(root->left) , 0);
        int rightGain =max( maxGain(root->right) , 0);

        int pricePath = root->val + leftGain + rightGain;
        max_sum = max(max_sum,pricePath);
        return root->val + max(leftGain,rightGain);
    }

    int maxPathSum(TreeNode *root)
    {
        maxGain(root);

        return max_sum; 
    }
};
// @lc code=end
