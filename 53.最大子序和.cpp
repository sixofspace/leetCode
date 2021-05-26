/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //暴力法求解
        // int maxArr = INT_MIN;
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     int sum = 0;
        //     for (int j = i; j < nums.size(); j++)
        //     {
        //         sum += nums[j];
        //         if (maxArr < sum)
        //         {
        //              maxArr = sum;
        //         }
        //     }
        // }
        // return maxArr;        

        //动态规划求解 和接雨水 从左向右遍历 可以容易知道当前的最大值
        int maxArr = nums[0];
        int pre = 0;
        for (const auto &p : nums){
            pre = max(pre + p , p);
            maxArr = max(maxArr , pre);
        }
        return maxArr;
    }
};
// @lc code=end

