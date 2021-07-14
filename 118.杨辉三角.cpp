/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp;
        for (int i = 0; i < numRows; i++)
        {
            vector<int> temp(i+1 ,1);
            dp.push_back(temp);
        }
        for (int i = 2; i < numRows; i++)
        {
           for (int j = 1; j < dp[i].size() - 1; j++)
           {
               dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
           }
           
        }
        
        return dp;
    }
};
// @lc code=end

