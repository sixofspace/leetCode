/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        // 容易 的哈希表 求解
        // 使用count，返回的是被查找元素的个数。如果有，返回1；否则，返回0。注意，map中不存在相同元素，所以返回值只能是1或0。
        // 使用find，返回的是被查找元素的位置，没有则返回map.end()。
        // unordered_set<ListNode *> sets;
        // while (head)
        // {
        //     // if (sets.find(head) != sets.end())
        //     if (sets.count(head))
        //     {
        //         return head;
        //     }
        //     sets.emplace(head);
        //     head = head->next;
        // }
        // return nullptr;

        //快慢指针  
        // 慢指针 跑不完一圈必定被 快指针追上 
        // 再相遇点 fast 以正常速度往前 ，slow从开始
        if (!head || !head->next)
        {
            return nullptr;
        }

        ListNode * slow = head ;
        ListNode * fast = head ;
        while (true)
        {
            if (!fast || !fast->next)
            {
                return nullptr ;
            }
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }
        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
    }
};
// @lc code=end
