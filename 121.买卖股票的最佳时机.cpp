/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // //动态规划写
        // int n = prices.size( );
        // if (n < 2)
        // {
        //     return 0 ;
        // }
        // vector<int> dp(n,0);
        // int miniprice = INT_MAX;
        // dp[0] = 0;
        // for (int i = 1; i < n; i++)
        // {
        //     miniprice = min(miniprice , prices[i]);
        //     dp[i] = max(dp[i-1] , prices[i] - miniprice);
        // }
        // return dp[n-1];

        //动态规划 空间优化
        // int n = prices.size( );
        // if (n < 2)
        // {
        //     return 0 ;
        // }
        // int maxprprofit = 0;
        // int miniprice = INT_MAX;
 
        // for (int i = 0; i < n; i++)
        // {
        //     miniprice = min(miniprice , prices[i]);
        //     maxprprofit = max(maxprprofit , prices[i] - miniprice);
        // }
        // return maxprprofit;

        //符合了单调栈的应用场景 当你需要高效率查询某个位置左右两侧比他大（或小）的数的位置的时候
        // 在 pricesprices 数组的末尾加上一个 哨兵👨‍✈️(也就是一个很小的元素，这里设为 0))，就相当于作为股市收盘的标记(后面就清楚他的作用了)
        // 假如栈空或者入栈元素大于栈顶元素，直接入栈
        // 假如入栈元素小于栈顶元素则循环弹栈，直到入栈元素大于栈顶元素或者栈空
        // 在每次弹出的时候，我们拿他与买入的值(也就是栈底)做差，维护一个最大值。
        int maxprofit = 0;
        vector<int> st;
        prices.emplace_back(-1);/////!!!!!哨兵作用
        for (int i = 0; i < prices.size(); i++)
        {
            while (!st.empty() && st.back() > prices[i])
            {
                maxprofit = max(maxprofit , st.back() - st.front());
                st.pop_back();
            }
            st.push_back(prices[i]);
        }
        return maxprofit;
 
    }
};
// @lc code=end

