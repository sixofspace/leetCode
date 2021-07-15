/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == -2147483648 && divisor == -1) return 2147483647;
        return (long) dividend / divisor;
    }
};
// @lc code=end

