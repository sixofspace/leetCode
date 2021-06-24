// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem19.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        //注意 针对于 头结点的操作 ，需要设置一个哨兵节点 返回哨兵节点的next即可
        ListNode* fast = head;
        ListNode* dump = new ListNode(-1);
        dump->next = head;
        ListNode* slow = dump;
        
        while (n)
        {
           fast = fast->next;
           n--;
        }
        while (fast)
        {
            fast = fast->next;
            slow= slow->next;
        }
        if (slow->next->next)
        {
            slow->next = slow->next->next;
        }else{
            slow->next = nullptr;
        }
        
        
        return dump->next;
        
    }
};
// @lc code=end

