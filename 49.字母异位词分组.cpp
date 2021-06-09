/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //排序 
        //由于互为字母异位词的两个字符串包含的字母相同，因此对两个字符串分别进行排序之后得到的字符串一定是相同的，故可以将排序之后的字符串作为哈希表的键。
        vector<vector<string>> res;
        unordered_map<string ,vector<string>> mm;
        for (string &s : strs){
            string key = s;
            sort(key.begin() , key.end());
            mm[key].emplace_back(s);
        }
        for (auto it = mm.begin() ; it != mm.end() ; ++it){
            res.emplace_back(it->second);
        }
        return res;
    }
};
// @lc code=end

