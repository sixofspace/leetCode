// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
 

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
// #include <vector>
// #include <iostream>
// using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
//暴力法解决
        // for (int i = 0; i < nums.size() - 1 ; i++)
        // {   
        //     int a = nums[i];
        //     for (int j = i + 1; j < nums.size(); j++)
        //     {
        //          if(target - a == nums[j])
        //          {
        //              return {i,j};
        //          }
        //     }
            
        // }
        // return { };
        //哈希表解法
        unordered_map<int ,int > hashtable;
        for (int i = 0; i < nums.size(); i++)
        {
            auto it = hashtable.find(target - nums[i] );
            if (it != hashtable.end() )
            {
               return {it->second , i};
            }
            hashtable[nums[i]] = i;
        }
        return {};

    }
};
// @lc code=end

