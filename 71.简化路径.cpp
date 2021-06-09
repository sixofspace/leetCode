// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem71.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
using namespace std;
// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        // 先使用 StringStream 和 getline 分割字符串
        // 再使用栈 遇到。。 后退 。跳过等
        // "" 或 . ： 跳过
        // .. 而且数组不为空： 返回上一级，则删除数组最后一个元素
        // != '..' 则为有效的目录名： 插入到数组里
        stringstream ss(path);
        vector<string> strs;
        strs.reserve(20);
        string curr;
        while (getline(ss, curr, '/')){
            if (curr != "." && !curr.empty())
            {
                if (curr != ".." )
                {
                    strs.push_back(curr);
                }
                else if (!strs.empty())
                {
                    strs.pop_back();
                }
            }
            
        }
        if (!strs.empty())
        {
            string res = "";
            for (string str : strs)
            {
                res.append("/");
                res.append(str);
            }
            return res;
        }
        else
        {
            // 为空，直接返回 "/"
            return "/";
        }
    }
};
// @lc code=end

