// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem234.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */
// #include <vector>
// #include <unordered_set>
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
    bool isPalindrome(ListNode* head) {
        ListNode* reverseList = nullptr;
        ListNode* curr = head;
        while (curr)
        {
            if (curr == head)
            {
                reverseList = new ListNode(curr->val);
            }else{
                ListNode* node = new ListNode(curr->val);
                node->next = reverseList;
                reverseList = node;
            }
            curr = curr->next;
        }
        while (head)
        {
            if (head->val != reverseList->val)
            {
                return false;
            }
            head = head->next;
            reverseList = reverseList->next;
        }
        return true;
    }
};
// @lc code=end

