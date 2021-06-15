/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:

//  原问题可以分解成规模较小的两个子问题，且子问题的解可以复用。因此，我们可以想到使用动态规划来求解本题。
//  1.动态规划求解
    int numTrees(int n) {
        vector<int> G(n+1 , 0);
        G[0] = 1;
        G[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                G[i] += G[j -1]*G[i-j]; 
            }
        }
        return G[n];        
    }
};
// @lc code=end

