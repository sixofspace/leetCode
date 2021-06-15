/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

 //Definition for a binary tree node.
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
    // 
    // vector<int> ans;
    // void test(TreeNode* root){
    //     if (!root)
    //     {
    //         return ;
    //     }
    //     test(root->left);
    //     ans.push_back(root->val);
    //     test(root->right);
    // }
    // vector<int> inorderTraversal(TreeNode* root) {
    //     test(root);
    //     return ans;
    // }

    vector<int> inorderTraversal(TreeNode* root) {
    // 方法二：迭代
    // 方法一的递归函数我们也可以用迭代的方式实现，两种方式是等价的，区别在于递归的时候隐式地维护了一个栈，
    // 而我们在迭代的时候需要显式地将这个栈模拟出来，其他都相同，具体实现可以看下面的代码。
        vector<int> res;
        stack<TreeNode*> st;
        while (root != nullptr || !st.empty())
        {
            while (root != nullptr)
            {
                st.push(root);
                root = root ->left;   
            }
            // int top = st.top()->val;
            root = st.top();
            res.push_back(root->val);
            st.pop();
            root = root->right;
        }
        return res;
    }

    // 方法三：Morris 中序遍历 ？？？？？
};
// @lc code=end

