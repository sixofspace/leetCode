/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        ListNode *tail = new ListNode(-1);
        tail->next = head;
        ListNode *prekNode = tail;
        ListNode *fast = tail;
        int len = 0;
        while (tail->next)
        {
            len++;
            tail = tail->next;
        }
        if (len == 0 || k % len == 0)
        {
            return head;
        }
        
        k = k % len;
        //寻找倒数第k+1 个节点和 第k个节点
        // k+1 指向空指针 k节点变为首节点 原来的尾节点指向 head
        for (int i = 0; i < k; i++)
        {
            fast = fast->next;
        }
        while (fast != tail)
        {
            fast = fast->next;
            prekNode = prekNode->next;
        }
        ListNode *kNode = prekNode->next;
        prekNode->next = nullptr;
        tail->next = head;
        return kNode;
    }
};
// @lc code=end
