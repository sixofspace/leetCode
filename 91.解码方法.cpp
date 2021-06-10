/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
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
    int numDecodings(string s) {
        //使用动态规划 注意边界值
        int n = s.size();
        vector<int> f(n + 1);
        f[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            if (s[i - 1] != '0')
            {
                f[i] += f[i-1];

            }
            if ( i > 1 && s[i-2] != '0' && (s[i - 1] - '0') + (s[i - 2] - '0')*10 <= 26)
            {
                f[i] += f[i-2];    
            }
        }
        return f[n];        
    } 
};
// @lc code=end

