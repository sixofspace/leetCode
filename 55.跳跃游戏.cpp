/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxposition = 0 ;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            maxposition = max(maxposition , i + nums[i]);
            if (maxposition == i)
            {
               return false;
            }
        }
        return true;

    }
};
// @lc code=end

