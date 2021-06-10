// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem76.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
using namespace std;
// @lc code=start
class Solution {
public:
    unordered_map<char , int > ori , target;
    bool checkTartgetValid(){
        for(const  auto &p : ori){
            if (target[p.first] < p.second)
            {
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {

        //滑动窗口 可以看做是一种双指针的特例方法
        int l = 0;
        int r = -1;
        int len = INT_MAX;
        int minL = -1;
        for (const  auto & c : t){
            ++ori[c];
        }
        while (r < int (s.size()))
        {
             if (ori.find(s[++r]) != ori.end())
             {
                 ++target[s[r]];
             }
             while (checkTartgetValid() && l <= r)
             {
                  if (r - l + 1 < len)
                  {
                       len = r - l + 1;
                       minL = l;
                  }
                  if (ori.find(s[l]) != ori.end())
                  {
                       --target[s[l]];
                  }
                  l++;
             }
 
        }
         return minL == -1 ? string() : s.substr(minL, len);


    }
};
// @lc code=end

