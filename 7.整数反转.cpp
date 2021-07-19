/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution
{
public:
    int reverse(int x)
    {
        int res = 0;
        while (x)
        {
            if (res < INT_MIN / 10 || res > INT_MAX / 10) { //注意整数的取值范围
                return 0;
            }
            int cur = x % 10;
            x = x / 10;
            res = res * 10 + cur;
        }
        return res;
    }
};
// @lc code=end
