/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <stack>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> t;
    void backtracking(vector<int>& nums , vector<int> &path ,int startindex ){
        res.push_back(path);
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > startindex &&  nums[i] == nums[i-1])
            {
                continue;
            }
            
            path.push_back(nums[i]);
            backtracking(nums, path , i + 1);
            path.pop_back();
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        backtracking(nums,t,0);
        return res;
    }
};
// @lc code=end

