// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem148.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
    ListNode* sortList(ListNode* head) {

    }
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* dumpHead = new ListNode(-1);
        ListNode* dump = dumpHead;
        while (left && right)
        {
            if (left->val <= right->val)
            {
                dump->next = left;
                left = left->next;
            }else{
                dump->next = right;
                right = right->next;
            }
            dump = dump->next;
        }
        if (left)
        {
            dump->next = left;
        }
        if (right)
        {
            dump->next = right;
        }
        return dumpHead->next;
    }
    ListNode* sortLists(ListNode* head, ListNode* tail) {
        if (!head)
        {
            return head;
        }
        if (head->next == tail) //将尾结点 去除 因为尾结点要么为空 要么就是重复的中间结点
        {
            head->next = nullptr;
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != tail)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail)
            {
                fast = fast->next;
            }
        }
        ListNode* mid = slow;
        ListNode* left = sortLists(head , slow);
        ListNode* right = sortLists(slow , tail);
        return merge(left,right);
        
    }

    ListNode* sortList(ListNode* head) {
        return sortLists(head, nullptr);
    }



};
// @lc code=end

