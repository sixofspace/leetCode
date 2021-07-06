/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution
{
public:
// 大的不同就是for循环里不用startIndex了。

// 因为排列问题，每次都要从头开始搜索，例如元素1在[1,2]中已经使用过了，但是在[2,1]中还要再使用一次1。

    vector<int> vis;
    void backtracking(vector<vector<int>> &res, vector<int> &nums, int first , vector<int> temp)
    {
        if (first == nums.size())
        {
            res.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])) {
                continue;
            }
            vis[i] = 1;
            // swap(nums[i], nums[first]);
            temp.push_back(nums[i]);
            backtracking(res, nums, first + 1 , temp);
            vis[i] = 0;
            temp.pop_back();
            // swap(nums[i], nums[first]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vis.resize(nums.size());
        vector<vector<int>> res;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        backtracking(res, nums, 0 , temp);
        return res;
    }
};
// @lc code=end
