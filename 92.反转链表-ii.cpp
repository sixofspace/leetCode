/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dump = new ListNode(-1);
        dump->next = head;
        ListNode* pre = dump;
        ListNode* headNode = nullptr;
        ListNode* tailNode = nullptr;
        ListNode* lefthead = new ListNode(-1);
        ListNode* righttail = new ListNode(-1);
        int k = 1;
        while (head)
        {
            if (left == k)
            {
                lefthead = head;
                headNode = pre;
            }
            if (right == k)
            {
                righttail = head;
                break;
            }
            head = head->next;
            pre = pre->next;
            k++;
        }
        tailNode = righttail->next;
        while (tailNode != righttail)
        {
            ListNode* nex = lefthead->next;
            lefthead->next = 
        }
        

    }
};
// @lc code=end

