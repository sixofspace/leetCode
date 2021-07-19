// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem8.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
 
    int myAtoi(string s) {
        long len = s.size();
        int res = 0;

        //去除前导空格
        int index = 0;
        while (index < len)
        {
            if (s[index] != ' ')
            {
                break;
            }
            index++;
        }
        
        if (index == len)
        {
            return 0;
        }
 
        int sign = 1;
        if (s[index] == '+')
        {
            index++;
        }else if (s[index] == '-')
        {
            sign = -1;
            index++;
        }
        

        for (; index < len; index++)
        {
            char curchar = s[index];
            if (curchar < '0' || curchar > '9') {
                break;
            }
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && (curchar - '0') > INT_MAX % 10)) {
                return INT_MAX;
            }
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && (curchar - '0') > -(INT_MIN % 10))) {
                return INT_MIN;
            }

            res = res *10 + (curchar - '0') * sign;
        }
        return res;

    }
};
// @lc code=end

