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
        // int n = haystack.size();
        // int n1 = needle.size();
        // if (n1 == 0)
        // {
        //     return 0;
        // }
        // if (n < n1)
        // {
        //     return -1;
        // }
        // for (int i = 0; i < n; i++)
        // {
        //     int k = i;
        //     for (int j = 0; j < n1; j++)
        //     {
        //         if (haystack[k] == needle[j])
        //         {
        //              if ( k - i + 1 == n1  )
        //              {
        //                  return i;
        //              }
        //         }else{
        //             break;
        //         }
        //         k++;
        //     }
        // }
        // return -1;

        //KMP 算法
        // 1.next 数组的计算
        // 2. 原始串 i 不变 ， 匹配串 指针j 指向next[j] 
        // 参考  leetcode-cn.com/problems/implement-strstr/solution/shua-chuan-lc-shuang-bai-po-su-jie-fa-km-tb86/
        int n = haystack.size();
        int m = needle.size();

        if ( m == 0)
        {
            return 0 ;
        }
        //设置哨兵
        haystack.insert(haystack.begin() , ' ');
        needle.insert(needle.begin() , ' ' );
        vector<int> next(m + 1);

        for (int i = 2 , j = 0 ; i <= m; i++)
        {
             while ( j && needle[i] != needle[j + 1] )
             {
                  j = next[j];
             }
             if (needle[i] == needle[j+1])
             {
                 j++;
             }
             next[i] = j;
        }
        for (int i = 1 , j = 0; i <= n; i++)
        {
            while (j && haystack[i] != needle[ j + 1])
            {
                j = next[j];
            }
            if (haystack[i] == needle[j+1])
            {
                j++;
            }
            if ( j == m)
            {
                return i - m ;
            }
            
        }
        
        return -1;
        

    }
};
// @lc code=end

