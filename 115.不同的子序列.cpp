/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        s = " " + s;
        t = " " + t;
        vector<vector<int>> dp(n + 1,vector<int>(m + 1,0));
        for(int i = 0; i < n; i++) dp[i][0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                dp[i][j] = dp[i - 1][j];
                if(s[i] == t[j]) dp[i][j] = (0LL + dp[i][j] + dp[i - 1][j - 1]) % INT_MAX;
            }
        }
        return dp[n][m];
// 需要说明的是，由于中间结果会溢出，CPP 中必须使用 long long，而 Java 不用。
// 由于 Java 中 int 的存储机制，只要在运算过程中只要不涉及取 min、
// 取 max 或者其他比较操作的话，中间结果溢出不会影响最终结果。



    }
};
// @lc code=end

