// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem39.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
// @lc code=start
class Solution
{
public:
    // 对于这类寻找所有可行解的题，我们都可以尝试用「搜索回溯」的方法来解决。

    // 回到本题，我们定义递归函数 dfs(target, combine, idx) 表示当前在 candidates 数组的第 idx 位，还剩 target 要组合，已经组合的列表为 combine。递归的终止条件为 target <= 0 或者 candidates 数组被全部用完。那么在当前的函数中，每次我们可以选择跳过不用第 idx 个数，即执行 dfs(target, combine, idx + 1)。也可以选择使用第 idx 个数，即执行 dfs(target - candidates[idx], combine, idx)，注意到每个数字可以被无限制重复选取，因此搜索的下标仍为 idx。

    // void dfs(vector<int>& candidates, int target ,vector<vector<int>> &res ,vector<int> &combine , int idx  ){
    //     if (idx == candidates.size())
    //     {
    //         return ;
    //     }
    //     if (target == 0)
    //     {
    //         res.push_back(combine);
    //         return ;
    //     }
    //     dfs(candidates , target , res, combine , idx + 1);
    //     if (target - candidates[idx] >= 0)
    //     {
    //          combine.push_back(candidates[idx]);
    //          dfs(candidates,target - candidates[idx] , res , combine , idx );
    //          combine.pop_back();
    //     }

    // }
    //剪枝优化
    vector<vector<int>> res;
    vector<int> combine;

    void backtracking(vector<int> &candidates, int target, int sum, int startIndex)
    {
        if (sum == target)
        {
            res.push_back(combine);
            return;
        }
        if (sum > target)
        {
            return;
        }
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++)
        {
             sum += candidates[i];
             combine.push_back(candidates[i]);
             backtracking(candidates , target , sum , i);
             sum -= candidates[i];
             combine.pop_back();
        }
        
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        res.clear();
        combine.clear();

        sort(candidates.begin(), candidates.end());
        //方法一dfs(candidates, target, res, combine, 0);
        //方法二
        backtracking(candidates, target, 0, 0) ;
        return res;
    }
};
// @lc code=end
