/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       

// 排序加双指针
// 对 vector<vector<int>> 排序，需要按照先比较区间开始，如果相同再比较区间结束，使用默认的排序规则即可
// 使用双指针，左边指针指向当前区间的开始
// 使用一个变量来记录连续的范围 t
// 右指针开始往后寻找，如果后续的区间的开始值比 t 还小，说明重复了，可以归并到一起
// 此时更新更大的结束值到 t
// 直到区间断开，将 t 作为区间结束，存储到答案里
// 然后移动左指针，跳过中间已经合并的区间
 
        vector<vector<int>> res;
        if (intervals.size() < 2)
        {
             return intervals;
        }
        
        sort(intervals.begin() , intervals.end());
        for (int i = 0 ; i < intervals.size() ;  )
        {
            int j =  i + 1;
            int t = intervals[i][1];
            //需要一直合并就写一个循环
            while ( j < intervals.size() && t >= intervals[j][0])
            {
                 t = max(t , intervals[j][1]);
                 j++;
            }
            res.push_back({intervals[i][0] , t});
            i = j ;
        }
        return res;
        
    }
};
// @lc code=end

