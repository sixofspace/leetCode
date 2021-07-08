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
    void backtracking(vector<int>& nums , vector<int> &path ,int startindex,vector<bool> &used ){
        res.push_back(path);
        for (int i = startindex; i < nums.size(); i++)
        {
            if (i > 0 &&  nums[i] == nums[i-1] && used[i -1] == false)
            {
                continue;
            }
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(nums, path , i + 1 ,used);
            path.pop_back();
            used[i] = false;
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<bool> used(nums.size(),false);
        backtracking(nums,t,0,used);
        return res;
    }
};
// @lc code=end

