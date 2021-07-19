/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
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
    bool isPalindrome(int x) {
       
        if (x < 0)
        {
            return false;
        }
        int rev = reverse(x);
        while (x)
        {
            int x1 = x % 10;
            int re = rev % 10;
            x = x / 10;
            rev = rev / 10;
            if (x1 != re)
            {
               return false;
            }
        }
        return true;
    }
};
// @lc code=end

