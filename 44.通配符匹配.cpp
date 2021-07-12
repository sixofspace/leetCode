/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> f(m+1 , vector<int>(n+1));
        f[0][0] = true;
        for (int i = 1; i <= n; i++)
        {
            if (p[i-1] == '*')
            {
                f[0][i] = true;
            }else{
                break;
            }
            
        }
        


        for(int i = 1 ; i <= m ; i++){
            for (int j = 1; j <= n; j++)
            {
                if (p[j - 1 ] == '*')
                {
                    f[i][j] = f[i][j-1] | f[i-1][j];
                }else if (s[i-1] == p[j-1] || p[j - 1] == '?')
                {
                    f[i][j] = f[i-1][j-1];
                }
            }
        }
        return f[m][n];
    }
};
// @lc code=end

