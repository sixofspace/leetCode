// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem120.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        //动态规划易求解
        //注意空间优化的方法！！！！
        int n = triangle.size();
        int mini = INT_MAX;
        vector<vector<int>> res(n,vector<int>(n));
        res[0][0] = triangle[0][0];
        for (int i = 1; i < triangle.size(); i++)
        {
            res[i][0] =  res[i-1][0] + triangle[i][0];
        }
        for (int i = 1; i < triangle.size(); i++)
        {
            res[i][i] =  res[i-1][i-1] + triangle[i][i];
        }

        for (int i = 2; i < triangle.size(); i++)
        {
            for (int j = 1; j < triangle[i].size() - 1 ; j++)
            {
                res[i][j] = min(res[i-1][j-1],res[i-1][j]) + triangle[i][j];
            }
        }

        for (int i = 0; i < triangle[n - 1].size(); i++)
        {
            if (mini > res[n-1][i])
            {
                 mini = res[n-1][i];
            }
            
        }
        
        return mini;

    }
};
// @lc code=end

