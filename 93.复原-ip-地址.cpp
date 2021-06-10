/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
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
class Solution
{

///????????为什么报错？？、
private:
    static constexpr int SEG_COUNT = 4;
    vector<string> ans;
    vector<int> segments;

 
public:

    void dfs(const string &s, int segId, int segStart)
    {
        if (segId == SEG_COUNT)
        {
            if (segStart == s.size())
            {
                string ipAddr;
                for (int i = 0; i < SEG_COUNT; i++)
                {
                    ipAddr += to_string(segments[i]);
                    if (i != SEG_COUNT - 1)
                    {
                        ipAddr += ".";
                    }
                }
                ans.push_back(move(ipAddr) );
            }
        }
        if (segStart == s.size())
        {
            return;
        }
        if (s[segStart] == '0')
        {
            segments[segId] = 0;
            dfs(s, segId + 1, segStart + 1);
        }
        int addr = 0;
        for (int i = segStart; i < s.size(); i++)
        {
            addr = addr * 10 + (s[i] - '0');
            if (addr > 0 && addr <= 0xFF)
            {
                segments[segId] = addr;
                dfs(s, segId + 1, i + 1);
            }
            else
            {
                break;
            }
        }
    }
    vector<string> restoreIpAddresses(string s)
    {
        segments.resize(SEG_COUNT);
        dfs(s, 0, 0);
        return ans;
    }
};
// @lc code=end
