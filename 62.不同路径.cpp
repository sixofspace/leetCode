/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
// @lc code=start
class Solution {
public:

    int uniquePaths(int m, int n) {
        vector<vector<int>> res(m,vector<int>(n,1));
        for (int i = 1; i < m; i++)
        {
             for (int j = 1; j < n; j++)
             {
                 res[i][j] = res[i-1][j] + res[i][j-1];
             }
             
        }
        return res[m-1][n-1];
    }
};
// @lc code=end

