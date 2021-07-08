/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */
#include <vector>
#include <stack>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        //动态规划的思想

        // int maxans = 0;
        // int n = s.length();
        // vector<int> dp(n, 0);

        // for (int i = 1; i < n; i++)
        // {
        //     if (s[i] == ')')
        //     {
        //         if (s[i - 1] == '(')
        //         {
        //             dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
        //         }
        //         else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(')
        //         {
        //             dp[i] = dp[i - 1] + ((i - dp[i - 1] >= 2) ? dp[i - dp[i - 1] - 2] : 0) + 2;
        //         }
        //         maxans = max(maxans, dp[i]);
        //     }
        // }
        // return maxans;

        //使用栈来解决
        stack<int> stk;
        int maxans = 0;
        stk.push(-1);
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                stk.push(i);
            }else{
                stk.pop();
                if (stk.empty())
                {
                   stk.push(i);
                }else{
                    maxans = max(maxans , i - stk.top());
                }
                
            }
            
        }
        return maxans;
        
    }
};
// @lc code=end
