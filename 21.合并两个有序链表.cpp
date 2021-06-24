/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
struct ListNode {
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* mergeList = new ListNode(-1);
        ListNode* dump = mergeList;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                mergeList->next = l1;
                l1 = l1->next;
            }else{
                mergeList->next = l2;
                l2 = l2->next;
            }
            mergeList = mergeList->next;
        }
        if (l1)
        {
            mergeList->next = l1;
        }
        if (l2)
        {
            mergeList->next = l2;
        }
        return dump->next;

    }
};
// @lc code=end

