/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int left = 0;
        int right = n - 1;
        int top = 0;
        int bottom = n - 1;
        int num = 1;
        while (left <= right && top <= bottom)
        {
            for (int i = left; i <= right; i++)
            {
                res[top][i] = num++;
            }

            for (int i = top + 1; i <= bottom; i++)
            {
                res[i][right] = num++;
            }
            ///注意这里
            if (left < right && top < bottom)
            {
                for (int i = right - 1; i > left; i--)
                {
                    res[bottom][i] = num++;
                }

                for (int i = bottom; i > top; i--)
                {
                    res[i][left] = num++;
                }
            }

            left++;
            right--;
            top++;
            bottom--;
        }
        return res;

        //   int num = 1;
        // vector<vector<int>> matrix(n, vector<int>(n));
        // int left = 0, right = n - 1, top = 0, bottom = n - 1;
        // while (left <= right && top <= bottom) {
        //     for (int column = left; column <= right; column++) {
        //         matrix[top][column] = num;
        //         num++;
        //     }
        //     for (int row = top + 1; row <= bottom; row++) {
        //         matrix[row][right] = num;
        //         num++;
        //     }
        //     if (left < right && top < bottom) {
        //         for (int column = right - 1; column > left; column--) {
        //             matrix[bottom][column] = num;
        //             num++;
        //         }
        //         for (int row = bottom; row > top; row--) {
        //             matrix[row][left] = num;
        //             num++;
        //         }
        //     }
        //     left++;
        //     right--;
        //     top++;
        //     bottom--;
        // }
        // return matrix;
    }
};
// @lc code=end
