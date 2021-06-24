// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem24.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */
// #include <vector>
// #include <queue>
// #include <iostream>
// using namespace std;
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dump = new ListNode(-1);
        dump->next = head;
        if (!head || !head->next)
        {
            return head;
        }
        ListNode* pre = dump;
        ListNode* first = head;
        ListNode* second = head->next;
        while (first && second)
        {
            pre->next = second;
            first->next = second->next;
            second->next = first;

            pre = first;
            if (first)
            {
                first = first->next;
            }else{
                break;
            }
            if (first)
            {
                second = first->next;
            }else{
                break;
            }
        }
        return dump->next;
    }
};
// @lc code=end

