/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //暴力解决
        // vector<vector<int>> res = {};
        // sort(nums.begin(),nums.end());
        // for (int i = 0; i < nums.size() - 2; i++)
        // {
        //     for (int j = i+1; j < nums.size() - 1 ; j++)
        //     {
        //         for (int k = j+ 1; k < nums.size() ; k++)
        //         {
        //             if (nums[i] + nums[j] + nums[k] == 0)
        //             {
        //                  vector<int> temp = {nums[i] , nums[j] , nums[k]};
        //                  res.push_back(temp);
        //             }
        //         }
        //     }
        // }
        // res.erase( unique( res.begin(), res.end() ), res.end() );
        // return res;

// 暴力法搜索为 O(N^3)O(N3) 时间复杂度，可通过双指针动态消去无效解来优化效率。
// 双指针法铺垫： 先将给定 nums 排序，复杂度为 O(NlogN)O(NlogN)。
// 双指针法思路： 固定 33 个指针中最左（最小）数字的指针 k，双指针 i，j 分设在数组索引 (k, len(nums))(k,len(nums)) 两端，通过双指针交替向中间移动，记录对于每个固定指针 k 的所有满足 nums[k] + nums[i] + nums[j] == 0 的 i,j 组合：
// 当 nums[k] > 0 时直接break跳出：因为 nums[j] >= nums[i] >= nums[k] > 0，即 33 个数字都大于 00 ，在此固定指针 k 之后不可能再找到结果了。
// 当 k > 0且nums[k] == nums[k - 1]时即跳过此元素nums[k]：因为已经将 nums[k - 1] 的所有组合加入到结果中，本次双指针搜索只会得到重复组合。
// i，j 分设在数组索引 (k, len(nums))(k,len(nums)) 两端，当i < j时循环计算s = nums[k] + nums[i] + nums[j]，并按照以下规则执行双指针移动：
// 当s < 0时，i += 1并跳过所有重复的nums[i]；
// 当s > 0时，j -= 1并跳过所有重复的nums[j]；
// 当s == 0时，记录组合[k, i, j]至res，执行i += 1和j -= 1并跳过所有重复的nums[i]和nums[j]，防止记录到重复组合。
        vector<vector<int>> res ;
        if(nums.size() < 3)
            return res;
        sort(nums.begin(),nums.end());
        for (int i = 0; i < nums.size() - 2; i++)
        {
            if(nums[i] > 0)
                break;
            if (i>0 && nums[i] == nums[i-1])
                continue;
            int L = i + 1;
            int R = nums.size() - 1;
            while (L < R)
            {
                if(nums[L] +nums[i] + nums[R] == 0){
                     vector<int> temp = {nums[i] , nums[L] , nums[R]};
                     res.push_back(temp);
                     while (L < R && nums[L] == nums[L+1] )
                     {
                         L++;
                     }
                    while (L < R && nums[R] == nums[R - 1] )
                     {
                         R--;
                     }
                     L++;
                     R--;
                }else if(nums[L] +nums[i] + nums[R] < 0){
                     L++;
                }else{
                     R--;
                }
            }
        }
        return res;
    }
};
// @lc code=end

