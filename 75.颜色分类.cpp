// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem75.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // //
        // sort(nums.begin(),nums.end() );

        //一趟扫描一般都是双指针
        //设置p0 代表0 设置p2代表2 找到0就和前面交换一下，找到2就和后面交换一下
        // !!!注意必须先判断p2 才可以

        int n = nums.size();
        int p0 = 0 ;
        int p2 = n - 1;

        for (int i = 0; i <= p2; i++)
        {

            while (i <= p2 && nums[i] == 2)
            {
               swap(nums[p2--] , nums[i]);
            }
            if (nums[i] == 0)
            {
               swap(nums[p0++] , nums[i]);
            }

        }
        
    }
};
// @lc code=end

