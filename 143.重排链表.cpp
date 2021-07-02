/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
    ListNode* findMidNode(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr )
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* head){
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur != nullptr )
        {
            ListNode* nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        return pre;
    }
    void merge(ListNode* l1 ,ListNode* l2){
        ListNode* l1_next;
        ListNode* l2_next;

        while (l1 && l2)
        {
            l1_next = l1->next;
            l2_next = l2->next;

            l1->next = l2;
            l1 = l1_next;

            l2->next = l1;
            l2 = l2_next;
        }
    }
    
    void reorderList(ListNode* head) {
        //线性表 求解 将链表存储在线性表中 然后根据下表直接遍历求解

        // vector<ListNode*> vec;
        // while (head)
        // {
        //     vec.push_back(head);
        //     head = head->next;
        // }
        // int i = 0 ;
        // int j = vec.size() - 1;
        // while (i < j)
        // {
        //     vec[i]->next = vec[j];
        //     i++;
        //     if ( i == j)
        //     {
        //        break;
        //     }
        //     vec[j]->next = vec[i];
        //     j--;
        // }
        // vec[i]->next = nullptr; //注意设置尾节点

        // 还可以使用快慢指针找到中间节点 然后 将之后节点反转 再将两链表合并
        ListNode* mid = findMidNode(head);
        ListNode* l2 = mid->next;
        mid->next = nullptr;
        l2 = reverse(l2);
        merge(head,l2);

    }
};
// @lc code=end

