/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<vector<int>> res;
    vector<int> path;

    void testback( vector<vector<int>> &res ,vector<int> &path ,  TreeNode* root, int targetSum){
        if (!root)
        {
            return;
        }
        path.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr)
        {
           if (root->val == targetSum)
           {
               res.push_back(path);
           }
        }
        testback(res,path,root->left , targetSum - root->val);        
        testback(res,path,root->right , targetSum - root->val);     
        path.pop_back();   //恢复路径？？？ 每层最后做出选择后，需要及时将其撤销

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        testback(res,path,root,targetSum);
        return res;
    }
};
// @lc code=end

