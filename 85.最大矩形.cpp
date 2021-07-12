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

        int n = matrix[0].size();
        int m = matrix.size();
        int maxArce = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == '1')
                {
                    bool flag = true;
                    int weight = 0;
                    int heigh = 0;
                    while (matrix[i][j + weight] == '1')
                    {
                        weight++;
                    }
                    while (matrix[i + heigh][j] == '1' && flag)
                    {
                        heigh++;
                        for (int k = 0; k <= weight; k++)
                        {
                            maxArce = max(maxArce, (k + 1) * heigh);
                            if (matrix[i + heigh][j + k] == '0')
                            {
                                heigh--;
                                flag = false;
                                break;
                            }
                        }
                    }
                }
            }
        }
        return maxArce;
    }
};
// @lc code=end
