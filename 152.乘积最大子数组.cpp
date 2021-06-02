// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem152.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
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
    int maxProduct(vector<int> &nums)
    {
        //暴力法解决
        // int n = nums.size();
        // int maxnums = INT_MIN;
        // if (n == 0 )
        // {
        //    return 0;
        // }else if (n == 1)
        // {
        //     return nums[0];
        // }

        // for (int i = 0; i < n ; i++)
        // {
        //     int temp = 1;
        //     for (int j = i ; j < n; j++)
        //     {
        //          temp = temp * nums[j];
        //          maxnums = max(maxnums , temp);
        //     }
        // }
        // return maxnums;

        //动态规划
        // int n = nums.size();
        // vector<int> maxF(nums);
        // vector<int> minF(nums);
        // for (int i = 1; i < n; i++)
        // {
        //     maxF[i] = max(maxF[i - 1] * nums[i] , max(minF[i - 1] * nums[i] , nums[i]));
        //     minF[i] = min(minF[i - 1] * nums[i] , min(maxF[i - 1] * nums[i] , nums[i]));
        // }
        // return *max_element(maxF.begin(),maxF.end());

        //动态规划 空间优化
        int n = nums.size();
        int res = nums[0];
        int maxF = nums[0];
        int minF = nums[0];
        for (int i = 1; i < n; i++)
        {
            int mx = maxF, mn = minF;
            maxF = max(mx * nums[i] , max(mn * nums[i] , nums[i]));
            minF = min(mn * nums[i] , min(mx * nums[i] , nums[i]));

            //不能直接复制 minF用到maxf 会导致minF值出错
            // maxF = max(maxF * nums[i] , max(minF * nums[i] , nums[i]));
            // minF = min(minF * nums[i] , min(maxF * nums[i] , nums[i]));
            res = max(res, maxF);
        }
        return res;
    }
};
// @lc code=end
