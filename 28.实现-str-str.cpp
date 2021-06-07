// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem28.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {

        //暴力求解  记得在使用KMP算法求解
        int n = haystack.size();
        int n1 = needle.size();
        if (n1 == 0)
        {
            return 0;
        }
        if (n < n1)
        {
            return -1;
        }
        for (int i = 0; i < n; i++)
        {
            int k = i;
            for (int j = 0; j < n1; j++)
            {
                if (haystack[k] == needle[j])
                {
                     if ( k - i + 1 == n1  )
                     {
                         return i;
                     }
                }else{
                    break;
                }
                k++;
            }
        }
        return -1;
        

    }
};
// @lc code=end

