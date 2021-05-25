/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 0 0 -> 0 2
        // 0 1 -> 1 2
        // 0 2    2 2
        // 0 n    n n-0
        // 1 0 -> 0 1
        // 1 1 -> 1 1
        // 1 2    2 1
        // 2 0 -> 0 0
        // 2 1 -> 1 0
        // 2 2    2 0
        // int n = matrix.size();
        // // vector<vector<int>> roMatrix(n,vector(n,0));  
        // // for (int i = 0; i < roMatrix.size(); i++)
        // // {
        // //     for (int j = 0; j < roMatrix[0].size(); j++)
        // //     {
        // //         roMatrix[i][j] = matrix[i][j];
        // //     }
            
        // // }
        //    // C++ 这里的 = 拷贝是值拷贝，会得到一个新的数组!!
        // auto roMatrix = matrix;
        // for (int i = 0; i < matrix.size(); i++)
        // {
        //     for (int j = 0; j < matrix[0].size(); j++)
        //     {
        //          matrix[j][matrix[0].size() - i - 1] = roMatrix[i][j] ;
        //     }
            
        // }

        //翻转 代替旋转
        // 先水平翻转
        // 在主对角线翻转
        int n = matrix.size();
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                swap(matrix[i][j] , matrix[n-i-1][j]);
            }
        }
        for (int i = 0; i < n ; i++)
        {
            for (int j = 0; j < i; j++)
            {
                swap(matrix[i][j] , matrix[j][i]);
            }
        }
    }
};
// @lc code=end

