/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        // 一个指针 i 进行数组遍历，另外一个指针 j 指向有效数组的最后一个位置。
        // 只有当 i 所指向的值和 j 不一致（不重复），才将 i 的值添加到 j 的下一位置。
        if (nums.size() < 2 )
        {
           return nums.size();
        }
        
        int i = 0 ;
        for (int j = 1; j < nums.size(); j++)
        {
            if ( nums[i] != nums[j])
            {
                nums[++i] = nums[j];  
            }
        }
        return ++i;

    }
};
// @lc code=end

