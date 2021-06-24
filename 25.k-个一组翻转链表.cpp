/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    pair<ListNode *, ListNode *> reverse(ListNode *head, ListNode *tail)
    {
        ListNode *dump = new ListNode(-1);
        ListNode *tail1 = nullptr;
        while (head != tail->next)
        {
            ListNode *temp = head;
            head = head->next;
            temp->next = dump->next;
            dump->next = temp;
            if (head == tail)
            {
                tail1= head;
            }
            
        }
        return {dump->next ,tail1 };
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *ans = new ListNode(-1);
        ans->next = head;
        while (head)
        {
            
            pair<ListNode*, ListNode*> result = result()
            // for (int i = 0; i < k; i++)
            // {
            //     if (head)
            //     {
            //         break;
            //     }
            //     head = head->next;
            // }
        }
        return ans;
    }
};
// @lc code=end
