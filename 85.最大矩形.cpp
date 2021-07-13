// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem85.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        //84 题 的所有的方法都可以在这题目使用
        //有时候 从尾节点 向前遍历更容易解决问题；
        if (matrix.size() == 0) {
            return 0;
        }
        int n = matrix[0].size();
        int m = matrix.size();

        
        int maxArce = 0;
        vector<vector<int>> left(m , vector<int>(n,0)); //使用该数组记录当前 以当前数字结尾的连续 1 的个数

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == '1')
                {
                    left[i][j] = (j == 0 ? 0 : left[i][j-1]) + 1;
                    int minWidth = left[i][j];

                    //向上扩展
                    for (int k = i; k >= 0; k--)
                    {
                        minWidth = min(left[k][j] , minWidth);
                        maxArce = max(maxArce , (i - k + 1)*minWidth);
                    }
                    
                }
                
            }
        }
        return maxArce;
    }
};
// @lc code=end
