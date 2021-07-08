/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    void backtacking(vector<vector<int>> &res,vector<int> &path,int cur , int k , int n){
        if (path.size() == k)
        {
           res.push_back(path);
           return;
        }
        
        for (int i = cur; i < n; i++)
        {

           path.push_back(i+1);
           backtacking(res,path,i+1,k,n); // 注意这里是使用 i + 1 组合不包含重复 元素 
           path.pop_back();

        }
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> path;

        backtacking(res,path, 0 , k, n );
        
        return res;


    }
};
// @lc code=end

