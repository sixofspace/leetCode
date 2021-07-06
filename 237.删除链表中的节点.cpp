/*
 * @lc app=leetcode.cn id=237 lang=cpp
 *
 * [237] 删除链表中的节点
 */
#include <vector>
#include <unordered_set>
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
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        // 把当前节点改为下一个节点的复制 然后删除 下一个节点

        node->val = node->next->val;
        node->next = node->next->next;
        
    }
};
// @lc code=end

