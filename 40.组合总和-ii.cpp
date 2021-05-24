/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> res;
    vector<int> combine;
    void dfs(vector<int> &candidates, int target, int sum , int start_index)
    {
        if (sum > target)
        {
            return;
        }
        if (sum == target)
        {
            res.push_back(combine);
            return;
        }
        for (int i = start_index; i < candidates.size() && sum + candidates[i] <= target; i++)
        {
            if (i != start_index && candidates[i] == candidates[i - 1])
            {
                 continue;
            }
            sum += candidates[i];
            combine.push_back(candidates[i]);
            dfs(candidates,target ,sum , i + 1 );
            sum -= candidates[i];
            combine.pop_back();
            
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        res.clear();
        combine.clear();
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target,0, 0);
        return res;
    }
};
// @lc code=end
