/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
     //深度拷贝 需要理解好在写 https://leetcode-cn.com/problems/fu-za-lian-biao-de-fu-zhi-lcof/solution/jian-zhi-offer-35-fu-za-lian-biao-de-fu-zhi-ha-xi-/
    // 建立新链表和 原先链表的 映射关系 ，在遍历构建新链表
public:

    Node* copyRandomList(Node* head) {
        if (!head)
        {
            return nullptr;
        }
        Node* cur = head;
        unordered_map<Node*, Node*> dic;
        while (cur)
        {
            dic[cur] = new Node(cur->val);
            cur = cur->next;
        }
        cur = head;
        while (cur)
        {
            dic[cur]->next = dic[cur->next];
            dic[cur]->random = dic[cur->random];
            cur = cur->next;
        }
        return dic[head];
    }
};
// @lc code=end

