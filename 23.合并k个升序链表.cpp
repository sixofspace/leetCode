/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 */
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
struct ListNode {
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* mergeList = new ListNode(-1);
        ListNode* dump = mergeList;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                mergeList->next = l1;
                l1 = l1->next;
            }else{
                mergeList->next = l2;
                l2 = l2->next;
            }
            mergeList = mergeList->next;
        }
        if (l1)
        {
            mergeList->next = l1;
        }
        if (l2)
        {
            mergeList->next = l2;
        }
        return dump->next;

    }
    // 最直接的 顺序合并
    // ListNode* mergeKLists(vector<ListNode*>& lists) {
    //     ListNode* ans = nullptr ;
    //     for (int i = 0; i < lists.size(); i++)
    //     {
    //         ans = mergeTwoLists(ans,lists[i]);
    //     }
    //     return ans;
    // }
    ListNode* merge(vector<ListNode*>& lists , int l , int r){
        if (l == r)
        {
           return lists[l];
        }
        if (l > r)
        {
           return nullptr;
        }
        int mid = (l + r) >> 1;
        return mergeTwoLists(merge(lists , l , mid),merge(lists ,mid + 1 , r));
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // 特别注意 长度需要减 1
        return merge(lists , 0 , lists.size() - 1);
    }

    // 优先队列解法 以后再琢磨一下
};
// @lc code=end

