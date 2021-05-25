/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {


//思路：首先从左向右遍历得到每一个当前位置的前面所有的最大值 leftMax(i)，
        //然后从右向左遍历得到每一个当前位置后面的最大值 rightMax(i)
        //那么此时当前位置能够盛的雨水值为 min(rightMax(i),leftMax(i)) - height(i)
//动态规划解法：
    // int  n = height.size();
    // int res = 0;
    // if ( n < 3)
    // {
    //     return 0;
    // }
    // vector<int> leftMax(n);
    // leftMax[0] = height[0];
    // for (int i = 1; i < n; i++)
    // {
    //     leftMax[i] = max(leftMax[i-1] , height[i]);
    // }
    
    // vector<int> rightMax(n);
    // rightMax[n - 1] = height[n - 1];
    // for (int i = n - 2; i > 0 ; i--)
    // {
    //     rightMax[i] = max(rightMax[i+1] , height[i]);
    // }
    
    // for (int i = 1; i < n -1 ; i++)
    // {
    //     res += min(leftMax[i],rightMax[i]) - height[i];
    // }
    // return res;




// 双指针法法

// 我们先明确几个变量的意思：

// left_max：左边的最大值，它是从左往右遍历找到的
// right_max：右边的最大值，它是从右往左遍历找到的
// left：从左往右处理的当前下标
// right：从右往左处理的当前下标
// 定理一：在某个位置i处，它能存的水，取决于它左右两边的最大值中较小的一个。

// 定理二：当我们从左往右处理到left下标时，左边的最大值left_max对它而言是可信的，但right_max对它而言是不可信的。（见下图，由于中间状况未知，对于left下标而言，right_max未必就是它右边最大的值）

// 定理三：当我们从右往左处理到right下标时，右边的最大值right_max对它而言是可信的，但left_max对它而言是不可信的。

//                                    right_max
//  left_max                             __
//    __                                |  |
//   |  |__   __??????????????????????  |  |
// __|     |__|                       __|  |__
//         left                      right
// 对于位置left而言，它左边最大值一定是left_max，右边最大值“大于等于”right_max，这时候，如果left_max<right_max成立，那么它就知道自己能存多少水了。无论右边将来会不会出现更大的right_max，都不影响这个结果。 所以当left_max<right_max时，我们就希望去处理left下标，反之，我们希望去处理right下标。
        int  n = height.size();
        int res = 0;
        if ( n < 3)
        {
            return 0;
        }
        int left = 0 ;
        int right = n -1 ;
        int leftMax = 0;
        int rightMax = 0;
        while (left < right)
        {
             leftMax = max(leftMax , height[left]);
             rightMax = max(rightMax , height[right]);
            if (leftMax <= rightMax)
            {
                res += leftMax - height[left];
                left++;
            }else{
                res += rightMax - height[right];
                right--;
            }
        }
        return res;        
   
    }
};
// @lc code=end

