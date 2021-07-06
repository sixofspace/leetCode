/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    void backtracking(vector<vector<int>> &res, vector<int>& nums, int first)
    {
        if (first == nums.size())
        {
            res.push_back(nums);
            return;
        }
        for (int i = first; i < nums.size(); i++)
        {
            swap(nums[i] , nums[first]);
            backtracking(res,nums,first + 1);
            swap(nums[i] , nums[first]);
        }
        
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtracking(res,nums,0);
        return res;
    }
};
// @lc code=end

