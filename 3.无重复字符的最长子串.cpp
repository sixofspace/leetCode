// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem3.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        //暴力 哈希求解
        // int max_num = 0;
        // if (s.size() == 1)
        // {
        //     return 1;
        // }

        // for (int i = 0; i < s.size(); i++)
        // {
        //     set<char> temp;
        //     for (int j = i; j < s.size(); j++)
        //     {
        //         if (temp.find(s[j]) == temp.end())
        //         {
        //             temp.insert(s[j]);
        //         }
        //         else
        //         {
        //             int t = temp.size();
        //             max_num = max(max_num, t);
        //             break;
        //         }
        //         int t = temp.size();
        //         max_num = max(max_num, t);
        //     }
        // }
        // return max_num;

        // 滑动窗口求解
        // int max_num = 0;
        // int n = s.size();
        // int rk = 0;
        // unordered_set<char> temp;

        // for (int i = 0; i < n; i++)
        // {
        //     if (i != 0)
        //     {
        //         temp.erase(s[i-1]);
        //     }
        //     while (rk < n && !temp.count(s[rk ]))
        //     {
        //         temp.insert(s[rk ]);
        //         rk++;
        //     }
        //     max_num = max(max_num , rk - i );
        // }
        // return max_num;


//https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/longest-substring-without-repeating-characters-b-2/
//很精练的解答
// 滑动窗口，保证每个窗口里字母都是唯一的

// 使用 vector<int> m 来记录一个字母如果后面出现重复时，i 应该调整到的新位置
//  所以每次更新的时候都会保存 j + 1 ，即字母后面的位置

// j 表示子串的最后一个字母，计算子串长度为 j - i + 1

 
        vector<int> m(128 , 0);
        int i = 0 ;
        int n = s.size();
        int ans = 0;
        for (int j = 0; j < n; j++)
        {
            i = max( i ,m[s[j]]);
            m[s[j]] = j + 1;
            ans = max(ans , j - i + 1);
        }
        return ans;
 
    }
};
// @lc code=end
