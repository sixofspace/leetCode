/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>>res;
    vector<int> t;
    void backtrack(vector<int> nums , vector<int> path , int start){
        res.push_back(path);
        for (int i = start; i < nums.size(); i++)
        {
            
            path.push_back(nums[i]);
            backtrack(nums,path,i+1);
            path.pop_back();
        }
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
// ①画出递归树，找到状态变量(回溯函数的参数)，这一步非常重要※
// ②根据题意，确立结束条件
// ③找准选择列表(与函数参数相关),与第一步紧密关联※
// ④判断是否需要剪枝
// ⑤作出选择，递归调用，进入下一层
// ⑥撤销选择
   //回溯总结 https://leetcode-cn.com/problems/subsets/solution/c-zong-jie-liao-hui-su-wen-ti-lei-xing-dai-ni-gao-/
    backtrack(nums,t,0);
    return res;
    }
};
// @lc code=end

