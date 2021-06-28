/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 */
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* test(vector<int>& nums, int left , int right){
        if (left > right)
        {
           return nullptr;
        }
        int node = ceil((left + right) / 2.0) ; // 还可以使用快慢指针找到中间节点
        TreeNode* root = new TreeNode(nums[node]);
        root->left = test(nums ,left , node-1 );
        root->right = test(nums ,node+1 , right );
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        while (head)
        {
            nums.push_back(head->val);
            head = head->next;
        }

        TreeNode* root = test(nums,0,nums.size() - 1);
        return root;
        
    }
};
// @lc code=end

