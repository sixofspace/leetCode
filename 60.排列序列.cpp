/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 排列序列
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:

    void backtacking(vector<string> &res,vector<bool> &used,string &list, int cur ,int n){
        if (cur == n)
        {
           res.push_back(list);
           return;
        }
        for (int i = 0; i < n; i++)
        {
            if (used[i] == true)
            {
               continue;
            }
            used[i] = true;
            char temp = '1' + i;
            list.push_back(temp);
            backtacking(res,used, list,cur + 1 , n);
            list.pop_back();
            used[i] = false;
        }
        

    }
    string getPermutation(int n, int k) {
        vector<string> res;
        string list;
        vector<bool> used(n , false);
        backtacking(res ,used , list,0, n );
        // sort(res.begin(),res.end());
        return res[k-1];
    }
};
// @lc code=end

