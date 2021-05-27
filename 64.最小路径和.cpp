// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem64.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //动态规划可求解 注意行列
        for (int i = 1; i < grid.size(); i++)
        {
            grid[i][0] +=  grid[i - 1][0];
        }
        for (int i = 1; i < grid[0].size(); i++)
        {
            grid[0][i] +=  grid[0][i - 1];
        }       

        for (int i = 1; i < grid.size(); i++)
        {
            for (int j = 1; j < grid[0].size(); j++)
            {
                grid[i][j] += min(grid[i-1][j] , grid[i][j-1]);
            }
        }
        return grid[grid.size()-1][grid[0].size()-1] ;
    }
};
// @lc code=end

