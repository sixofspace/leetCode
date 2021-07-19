// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem6.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        string res;
        vector<string> rows(min(numRows, int(s.size()))); 
        int currRow = 0 ;
        bool goDown = false;
        for ( char c: s)
        {
            rows[currRow] += c;
            if (currRow == 0 || currRow == numRows - 1)
            {
                goDown = !goDown;
            }
            currRow += goDown?  1 :-1;
        }
        
         for ( string r: rows){
             res += r;
         }
        return res;
        
        // 找规律计算
        // 第一次间距是step -2*i，第二次是2*i, 

    }
};
// @lc code=end

