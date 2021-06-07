// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem20.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
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
    bool isValid(string s) {
        int n = s.size();
        if ( n < 2)
        {
           return false;
        }
        
        stack<char> t;
        for (int i = 0; i < n; i++)
        {
            if ( s[i] == '(' || s[i] == '[' || s[i] == '{' )
            {
                t.push(s[i]);
            }
            if ( s[i] == ')' )
            {
                if ( !t.empty() && t.top() == '(')
                {
                    t.pop();
                }else{
                    return false;
                }               
            }else if (s[i] == ']'  )
            {
                if ( !t.empty() && t.top() == '[' )
                {
                    t.pop();
                }else{
                    return false;
                }  
            }else if (s[i] == '}' )
            {
                if ( !t.empty() && t.top() == '{')
                {
                    t.pop();
                }else{
                    return false;
                }  
            }
            
        }
        if (t.size() > 0)
        {
            return false;
        }
        return true;
    }
};
// @lc code=end

