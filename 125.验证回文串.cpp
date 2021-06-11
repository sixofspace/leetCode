// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem125.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
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
#include <math.h>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {

        //注意 字符床 api isalum 判断是否是数字和字符  
        // tolower转换为小写字母
 
        // stack<char> st;
        // if ( s.size() == 0)
        //     return true;

        // string s1;
        // for (int i = 0; i < s.size(); i++)
        // {
        //     if ( isalnum(s[i]) )
        //     {
        //         s1 += tolower(s[i]);
        //     }
        // }
 
        //使用栈
        // int n = s1.size();
        // for (int i = 0; i < n / 2; i++)
        // { 
        //     st.push(s1[i]);

        // }
        // for (int i = ceil(n / 2.0) ; i < n; i++)
        // {
        //     if(st.top() != s1[i]){
        //         return false;
        //     }
        //     st.pop();
        // }
        // return true;

        //使用双指针
        // int l = 0;
        // int r = n - 1;
        // while (l < r)
        // {
        //     if (s1[l] != s1[r])
        //     {
        //        return false;
        //     }
        //     l++;
        //     r--;
        // }
        // return true;

        //使用双指针 不用额外空间
        int l = 0;
        int r = s.size() - 1;
        while (l < r)
        {
            while (l < r && !isalnum(s[l]) )
            {
                l++;
            }
            while (l < r && !isalnum(s[r]) )
            {
                r--;
            }     
            if (l < r && (tolower(s[l]) != tolower(s[r])) )
            {
                return false;
            }
            l++;
            r--;
        }
        return true;

    }
};

// @lc code=end