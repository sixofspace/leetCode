// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem5.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {

        //暴力求解 遍历所有肯能 即可

        //但是使用动态规划 即可方便求解
        int n = s.size();
        if ( n < 2)
        {
            return s;
        }
        vector<vector<int>> dp(n,vector<int>(n));
        for (int i = 0; i < n; i++)
        {
           dp[i][i] = true;
        }
        int maxlen = 1;
        int start = 0;

        //枚举长度 
        for (int L = 1; L < n; L++)
        {
            //左边界
            for (int i = 0; i < n; i++)
            {
                //右边界
               int j = i + L ;
               if ( j >= n)
               {
                   break;
               }
               
               if(s[i] != s[j]){
                   dp[i][j] = false;
               }else{
                   if (j - i < 2)
                   {
                      dp[i][j] = true;
                   }else{
                      dp[i][j] = dp[i+1][j-1];
                   }
                   
               }

               if (dp[i][j] && (j - i + 1 > maxlen))
               {
                   maxlen = j - i + 1;
                   start = i;
               }
               
            }
            
        }
        return s.substr(start,maxlen);

    }
};
// @lc code=end

