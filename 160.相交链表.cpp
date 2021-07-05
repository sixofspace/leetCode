/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // unordered_set<ListNode *> tmpB;
        // while (headB)
        // {
        //     tmpB.emplace(headB);
        //     headB = headB->next;
        // }
        // while (headA)
        // {
        //     if (tmpB.find(headA) != tmpB.end())
        //     {
        //         return headA;
        //     }
        //     headA = headA->next;
        // }
        // return nullptr;

        // 方法二：双指针
        // 用数学的方法证明 两次移动的距离
        if (headA == nullptr || headB == nullptr)
        {
            return nullptr;
        }
        ListNode * ha = headA;
        ListNode * hb = headB;
        while (ha != hb)
        {
            ha = ha == nullptr ? headB : ha->next;
            hb = hb == nullptr ? headA : hb->next;
        }
        return ha;
    }
};
// @lc code=end

