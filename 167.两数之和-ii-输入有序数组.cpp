/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //暴力求解
        // int n = numbers.size();
        // if (n < 2)
        // {
        //     return {};
        // }
        
        // for (int i = 0; i < n - 1; i++)
        // {
        //     for (int j = i + 1; j < n; j++)
        //     {
        //         if (numbers[i] + numbers[j] == target)
        //         {
        //             return {i + 1 , j + 1};
        //         }
                
        //     }
            
        // }
        //  return {};


        //哈希表
        int n = numbers.size();
        unordered_map<int, int> umap;
 
        for (int  i = 0; i < n; i++)
        {
            auto it = umap.find(target - numbers[i]);
            if ( it != umap.end())
            {
                return {it->second , i + 1};
            }
            umap.emplace(numbers[i] , i + 1);
        }
        return {};



        //注意这题是有序 的可以用更优化的方法求解
    }
};
// @lc code=end

