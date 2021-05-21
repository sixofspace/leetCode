// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem27.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

 
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        //注意双指针 ！！！ 特别注意是左加还是右加
        int j = 0 ;
        for (int i = 0; i < nums.size() ; i++)
        {
            if (nums[i] != val)
            {
                 nums[j++] = nums[i];
            }
            
        }
        return j ;
        
    }
};
// @lc code=end

