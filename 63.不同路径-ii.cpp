// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem63.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
// @lc code=start
class Solution {
public:
// 

// !!!就可以考虑这种优化方法，目的是给空间复杂度「降维」。如果你还不知道什么是「滚动数组思想」，一定要查阅相关资料进行学习哦。
//动态规划
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rowflag = 1;
        int colflag = 1;
        int tmp = obstacleGrid[0][0];
        for (int i = 0; i < obstacleGrid[0].size(); i++)
        {

            if (obstacleGrid[0][i] == 1) {
                rowflag = 0;
            }
            obstacleGrid[0][i] = rowflag;
        }
        for (int i = 1; i < obstacleGrid.size(); i++)
        {
            if (obstacleGrid[i][0] == 1 || tmp == 1) {
                colflag = 0;
            }
            obstacleGrid[i][0] = colflag;
        }  
        for (int i = 1; i < obstacleGrid.size(); i++)
        {
            for (int j = 1; j < obstacleGrid[0].size(); j++)
            {
                if (obstacleGrid[i][j] == 0)
                {
                    obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
                }else if(obstacleGrid[i][j] == 1){
                    obstacleGrid[i][j] = 0;
                }
                
            }
            
        } //2 1 = 0 1 1 2 0
        return obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1] ;
        // return obstacleGrid[1][0];
    }
};
// @lc code=end

