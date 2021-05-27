/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
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
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() < 2)
        {
            return nums.size();
        }

        // int i = 0;
        int fast = 2;
        int slow = 2;
        while (fast < nums.size())
        {
            if (nums[slow -2] != nums[fast])
            {
                nums[slow ] = nums[fast];
                slow++;
            }
            fast++;
        }
        
        return slow;
    }
};
// @lc code=end
