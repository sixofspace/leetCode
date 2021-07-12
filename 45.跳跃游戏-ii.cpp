/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        // 可使用贪心进行正向遍历
        int end = 0;
        int maxposition = 0;
        int step = 0;
        for (int i = 0; i < nums.size() - 1; i++) //防止最后多遍历一次 step 多加1
        {
            maxposition = max(maxposition , nums[i] + i);
            if ( i == end)
            {
                end = maxposition;
                step++;
            }
            
        }
        
        return step;
    }
};
// @lc code=end

