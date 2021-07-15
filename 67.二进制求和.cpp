/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {

        string c;
        int flag = 0;
        reverse(a.begin(),a.end()); //注意字符串是从哪里开始的
        reverse(b.begin(),b.end());
        int n = max(a.size(),b.size());
        for (int i = 0; i < n; i++)
        {
            flag += i < a.size() ? a[i] -'0' : 0;
            flag += i < b.size() ? b[i] -'0' : 0;
            c.push_back(flag % 2 + '0');
            flag =  flag / 2;
        }
        if (flag)
        {
           c.push_back('1');
        }
        reverse(c.begin(),c.end());
        return c;

        // 还可以使用位运算
        
        
        
    }
};
// @lc code=end

