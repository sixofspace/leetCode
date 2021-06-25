// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem83.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 */
// #include <vector>
// #include <queue>
// #include <iostream>
// using namespace std;
// struct ListNode
// {
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dump = new ListNode(-1);
        dump->next = head;
        while (head && head->next)
        {
            if (head->next->val == head->val)
            {
                //循环的时候 空指针错误需要处理
                 head->next = head->next->next;
                // while (head->next->next)
                // {
                //     head->next = head->next->next;
                // }else{
                //     head->next = nullptr;
                //     break;
                // }
            }else
            {
                 head = head->next;
            }
        }
        return dump->next;
    }
};
// @lc code=end

