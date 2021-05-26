// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem57.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */
 
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        // 考虑不够全面
        // vector<vector<int>> res;
        // if (newInterval.empty()){
        //     return intervals;
        // }
        // if ( intervals.size() < 1 || intervals[intervals.size() - 1][1]  < newInterval[0])
        // {
        //      intervals.push_back(newInterval);
        //      return intervals;
        // }
        // for (int i = 0; i < intervals.size(); i++)
        // {
        //     if (i == 0 && intervals[0][0] > newInterval[1])
        //     {
        //         res.push_back(newInterval);
        //     }
            
        //     if (intervals[i][1] < newInterval[0] && intervals[i+1][0] > newInterval[1]  )
        //     {
        //          res.push_back(newInterval);
        //     }
        //     if (intervals[i][0] <= newInterval[0] && intervals[i][1] >= newInterval[0] || (i == 0 && intervals[0][0] < newInterval[1]))
        //     {
        //         int j = i ;
        //         int t = max(intervals[i][1] , newInterval[1]);
        //         while ( j < intervals.size() && t >= intervals[j][0])
        //         {
                     
        //              t = max(t , intervals[j][1]);
        //              j++;
        //         }
        //         res.push_back({min(intervals[i][0],newInterval[0]) , t});
        //         i = j - 1;
        //         continue;
        //     }
                
        //     res.push_back(intervals[i]);
           
            
        // }
        
        // return res;
 

 
 //那么我们应当在什么时候将区间 SS 加入答案呢？由于我们需要保证答案也是按照左端点排序的，因此当我们遇到第一个 满足 l_i > \textit{right}l 
// i
// ​	
//  >right 的区间时，说明以后遍历到的区间不会与 SS 重叠，并且它们左端点一定会大于 SS 的左端点。此时我们就可以将 SS 加入答案。特别地，如果不存在这样的区间，我们需要在遍历结束后，将 SS 加入答案。

 
        int left = newInterval[0];
        int right = newInterval[1];
        vector<vector<int>> res;
        bool place = false;
        for(const auto &interval : intervals){
            if (interval[0] > right)
            {
                if (!place)
                {
                    res.push_back({left,right});
                     place = true;
                }
                res.push_back(interval);
            }else if (interval[1] < left)
            {
    
                
                res.push_back(interval);
            }else{
                left = min(interval[0] , left);
                right = max(interval[1] ,right);
            }
        }
        if (!place)
        {
            res.push_back({left,right});
        }
        return res;
    }
};
// @lc code=end

