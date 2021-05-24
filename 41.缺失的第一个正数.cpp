/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        //将当前数组放入hash表中，开始从1每局未出现的最小整数
        set<int> a;
        for (int i = 0; i < nums.size(); i++)
        {
             a.insert(nums[i]);
        }
        for (int i = 1; ; i++)
        {
           if( a.find(i) == a.end())
            return i;
        }
        


    }
};
// @lc code=end

