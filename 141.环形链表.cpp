// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem141.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
    bool hasCycle(ListNode *head) {
        // 容易 的哈希表 求解
        // unordered_set<ListNode *> sets;
        // while (head)
        // {
        //     if (sets.find(head) != sets.end())
        //     {
        //         return true;
        //     }
        //     sets.emplace(head);
        //     head = head->next;
        // }
        // return false;    
        
        //快慢指针
        if (!head || !head->next)
        {
            return false;
        }
        
        ListNode * slow = head ;
        ListNode * fast = head->next ;
        while (slow != fast)
        {
            if (!fast || !fast->next)
            {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;

    }
};
// @lc code=end

