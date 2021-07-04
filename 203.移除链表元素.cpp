// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem203.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;
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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head)
        {
            return head;
        }
        
        ListNode* dump = new ListNode(-1);
        dump->next = head;
        ListNode* curr = dump;
        while (curr->next != nullptr)
        {
            if (curr->next->val == val)
            {
                curr->next != nullptr ? curr->next = curr->next->next : curr->next = nullptr ;
            }else{
                 curr = curr->next;
            }
            
        }
        return dump->next;

    }
};
// @lc code=end

