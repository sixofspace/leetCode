// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem25.h"

using namespace std;
// @before-stub-for-debug-end

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
    // 使用头插发 特别注意 指针的保存 尾指针的保存
    // pair<ListNode *, ListNode *> reverse(ListNode *head, ListNode *tail)
    // {
    //     ListNode *dump = new ListNode(-1);
    //     ListNode *last = tail->next;
    //     ListNode *tail1 = head;
    //     while (head != last)
    //     {
    //         ListNode *temp = head;
    //         head = head->next;
    //         temp->next = dump->next;
    //         dump->next = temp;
    //     }
    //     return {dump->next ,tail1 };
    // }
    // 使用尾插法

    pair<ListNode *, ListNode *> reverse(ListNode *head, ListNode *tail)
    {
        ListNode *prev = tail->next;
        ListNode *p = head;
        while (prev != tail)
        {
            ListNode *nex = p->next;
            p->next = prev;
            prev = p;
            p = nex;
        }
        return { tail,head };
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *ans = new ListNode(-1);
        ans->next = head;
        ListNode *pre = ans;
        while (head)
        {
            ListNode *tail = pre;
            for (int i = 0; i < k; i++)
            {
                tail = tail->next;
                if (!tail)
                {
                   return ans->next;
                }
            }
            ListNode *nex = tail->next;
            pair<ListNode*, ListNode*> result = reverse(head , tail);
            pre->next = result.first;
            result.second->next = nex;
            pre = result.second;
            head = pre->next;
        }
        return ans->next;
    }
};
// @lc code=end
