/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <stack>
using namespace std;
// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //暴力法会超时
        // if (heights.size() == 0)
        // {
        //     return 0;
        // }else if (heights.size() == 1)
        // {
        //     return heights[0];
        // }
        
        // int maxArea = 0;

        // for (int i = 0; i < heights.size() ; i++)
        // {
        //     int minheight = heights[i];
        //     for (int j = i ; j < heights.size(); j++)
        //     {
        //         if (minheight > heights[j] )
        //         {
        //             minheight = heights[j];
        //         }
        //         maxArea = max(maxArea  , minheight*(j - i + 1));
        //     }
        // }
        // return maxArea;        
        
        
        //需要学习单调栈的思想，来确定左右边界、

        int n = heights.size();
        vector<int> left(n) , right(n);
        stack<int> mono_stack;
        for (int i = 0; i < n; i++)
        {
            while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i])
            {
                mono_stack.pop();
            }
            left[i] = (mono_stack.empty() ? -1 : mono_stack.top());
            mono_stack.push(i);
        }
        mono_stack = stack<int>();
        
        for (int i = n - 1; i >= 0; i--)
        {
            while (!mono_stack.empty() &&  heights[mono_stack.top()]>= heights[i])
            {
                mono_stack.pop();
            }
            right[i] = (mono_stack.empty() ? n : mono_stack.top());
            mono_stack.push(i);
        }
        int maxArea = 0 ;
        for (int i = 0; i < n; i++)
        {
            maxArea = max(maxArea , (right[i] - left[i] - 1)* heights[i]);
        }
        return maxArea;
    }
};
// @lc code=end

