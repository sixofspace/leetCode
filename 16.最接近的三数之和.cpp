// @before-stub-for-debug-begin
#include <vector>
#include <string>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */
#include <vector>
#include <algorithm> 
#include <iostream>
using namespace std;
// @lc code=start
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        vector<vector<int>> res;
        if (nums.size() == 3)
            return nums[0] +nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        int mintarget = nums[0];
        int minval = 100000 ;
        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int L = i + 1;
            int R = nums.size() - 1;
            while (L < R)
            {

                if (nums[L] + nums[i] + nums[R] == target)
                {
                    vector<int> temp = {nums[i], nums[L], nums[R]};
                    res.push_back(temp);
                    while (L < R && nums[L] == nums[L + 1])
                    {
                        L++;
                    }
                    while (L < R && nums[R] == nums[R - 1])
                    {
                        R--;
                    }
                    L++;
                    R--;
                    return target;
                }
                else if (nums[L] + nums[i] + nums[R] < target)
                {
                    if (minval > abs(nums[L] + nums[i] + nums[R] - target))
                    {
                        minval = abs(nums[L] + nums[i] + nums[R] - target);
                        mintarget = nums[L] + nums[i] + nums[R];
                    }

                    L++;
                }
                else
                {
                    if (minval > abs(nums[L] + nums[i] + nums[R] - target))
                    {
                        minval = abs(nums[L] + nums[i] + nums[R] - target);
                        mintarget = nums[L] + nums[i] + nums[R];
                    }
                    R--;
                }
            }
        }
        return mintarget;
    }
};
// @lc code=end
