// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem2.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *l3 = nullptr;
        ListNode *pre = l3;
        int flag = 0;
        while (l1 || l2 || flag)
        {
            if (pre)
            {
                l3->next = new ListNode(((l1 != nullptr ? l1->val : 0) + (l2 != nullptr ? l2->val : 0) + flag) % 10);
                l3 = l3->next;
            }
            else
            {
                // 此时l3 指针已经变化 ，pre 指向之前的 l3 ,l3 = new ListNode ((l1 != nullptr ?  l1->val : 0) + (l2 != nullptr ?  l2->val : 0) + flag);
                pre = l3 = new ListNode(((l1 != nullptr ? l1->val : 0) + (l2 != nullptr ? l2->val : 0) + flag) % 10);
            }
            flag = ((l1 != nullptr ? l1->val : 0) + (l2 != nullptr ? l2->val : 0) + flag) / 10;

            if (l1)
            {
                l1 = l1->next;
            }
            if (l2)
            {
                l2 = l2->next;
            }
        }
        return pre;
    }
};
// @lc code=end
