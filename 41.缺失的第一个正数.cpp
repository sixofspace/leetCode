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

        // //将当前数组放入hash表中，开始从1每局未出现的最小整数
        // set<int> a;
        // for (int i = 0; i < nums.size(); i++)
        // {
        //      a.insert(nums[i]);
        // }
        // for (int i = 1; ; i++)
        // {
        //    if( a.find(i) == a.end())
        //     return i;
        // }
// 我们对数组进行遍历，对于遍历到的数 x，如果它在 [1, N] 的范围内，那么就将数组中的第 x-1
// 个位置（注意：数组下标从 0 开始）打上「标记」。在遍历结束之后，如果所有的位置都被打上了标记，
// 那么答案是 N+1，否则答案是最小的没有打上标记的位置加 1。

// 那么如何设计这个「标记」呢？由于数组中的数没有任何限制，因此这并不是一件容易的事情。
// 但我们可以继续利用上面的提到的性质：由于我们只在意 [1,N] 中的数，
// 因此我们可以先对数组进行遍历，把不在 [1,N] 范围内的数修改成任意一个大于 N 的数（例如 N+1）。
// 这样一来，数组中的所有数就都是正数了，因此我们就可以将「标记」表示为「负号」。
        //哈希算法
        // int n = nums.size();
        // for(int& num : nums){
        //     if (num <= 0)
        //     {
        //         num = n + 1;
        //     }
        // }
        // for (int i = 0; i < nums.size() ; i++)
        // {
        //     int num = abs(nums[i]);
        //     if (num <= n)
        //     {
        //         nums[num - 1] = -abs(nums[num - 1]);
        //     }
            
        // }
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     if(nums[i] > 0)
        //         return i + 1;
        // }
        
        // return n + 1 ;

        //置换

        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
            {
                swap(nums[nums[i] - 1] , nums[i]);
            }
            
        }
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != i + 1)
            {
                return i + 1;
            }
            
        }
        return n+1;
        


    }
};
// @lc code=end

