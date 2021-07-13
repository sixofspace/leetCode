/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // 动态规划 需要强加练习 字符类 感觉都可以转换为 二维数组 类似迷宫内问题求解
        int n = s1.size();
        int m = s2.size();
        int t = s3.size();
        if (n + m != t)
        {
           return false;
        }
        vector<vector<int>> dp(n+1 ,vector<int>(m+1 , false) );
        dp[0][0] = true;

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                int p = i + j -1 ;
                if (i > 0 )
                {
                    dp[i][j] |= dp[i-1][j]  && s1[i -1] == s3[p] ;
                }
                if (j > 0 )
                {
                    dp[i][j] |= dp[i][j-1] && s2[j -1] == s3[p];
                }
            }
            
        }
        return dp[n][m];

    }
};
// @lc code=end

