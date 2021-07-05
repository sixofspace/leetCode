// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem206.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // 头插法
        // ListNode* dump = new ListNode(-1);
        // dump->next = nullptr; //注意将尾结点置空
        // while (head)
        // {
        //     ListNode* temp = head->next;
        //     head->next = dump->next;
        //     dump->next = head;
        //     head = temp;
        // }
        // return dump->next;

        // 遍历更改了指针的指向
        ListNode* prev = nullptr;
        while (head)
        {
            ListNode* nextnode = head->next;
            head->next = prev;
            prev = head;
            head = nextnode;
        }
        return prev;

        //有时间理解递归的做法
    }
};
// @lc code=end

