/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        //按层序遍历
        vector<int> ans;
         if(matrix.empty()) return ans;
        int left = 0 ;
        int right = matrix[0].size() - 1;
        int top = 0;
        int bottom = matrix.size() - 1;

        while (true)
        {
            for (int i = left; i <= right; i++)
            {
                 ans.push_back(matrix[top][i]);
            }
            if (++top > bottom) break;
            for (int i = top; i <= bottom; i++)
            {
                ans.push_back(matrix[i][right]);
            }
            if (--right < left) break;
            for (int i = right; i >= left; i--)
            {
               ans.push_back(matrix[bottom][i]);
            }
             if (--bottom < top) break;
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(matrix[i][left]);
            }
             if (++left > right) break;
            
        }
        return ans;
        
    }
};
// @lc code=end

