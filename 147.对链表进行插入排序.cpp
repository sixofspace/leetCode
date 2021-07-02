// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem147.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
    
    pair<ListNode* ,ListNode*> insertNode(ListNode* dump , ListNode* curNode){
        pair<ListNode* ,ListNode*> ans;
        ListNode* pre = dump;
        ListNode* head = dump->next;
        bool flag = true;
        while (head)
        {
            if ((head->val > curNode->val) && flag)
            {
                curNode->next = pre->next;
                pre->next = curNode;
                pre = curNode;
                flag = false;
            }
            head = head->next;
            pre = pre->next;
        }
        if (flag)
        {
            pre->next = curNode;
            curNode->next = nullptr;
            ans.second = curNode;
        }else{
            ans.second = pre;
        }
        ans.first = dump->next;
        return ans;
        
    }
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next)
        {
            return head;
        }
        
        ListNode* curNode = head->next;
        ListNode* pre = head;
        // ListNode* cur = head;
        ListNode* dump = new ListNode(-1);
        dump->next = head;
        while (curNode)
        {
            ListNode* temp = curNode;

            curNode = curNode->next;
            pre->next = nullptr;
            temp->next = nullptr;

            // 将 temp 插入之前的链表中 
            pair<ListNode* ,ListNode*> dev = insertNode(dump,temp);

            //将排序好的链表 重新链接好
            dev.second->next = curNode;
            dump->next = dev.first;
            pre = dev.second;
        }
        return dump->next;
    }
};
// @lc code=end

