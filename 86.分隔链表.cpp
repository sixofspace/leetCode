/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
class Solution {
public:
// 链表考什么？就是哨兵节点+虚拟节点+链表指针的移动
// 别理解错了 只是单纯的比较x 的值得大小 ，而不是需要x的节点
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(-1);
        ListNode* smallHead = small;
        ListNode* large = new ListNode(-1);
        ListNode* largeHead = large;
        while (head)
        {
            if (head->val < x)
            {
                small->next = head;
                small = small->next;
            }else{
                large->next = head;
                large = large->next;              
            }
            head = head->next;
        }
        small->next = largeHead->next;
        large->next = nullptr;
        return smallHead->next;
    }
};
// @lc code=end

