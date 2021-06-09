/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
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
class Solution {
public:
    inline static unordered_map<char,string>MAP =
    {{'2',"abc"},{'3',"def"},{'4',"ghi"},
    {'5',"jkl"},{'6',"mno"},{'7',"pqrs"},
    {'8',"tuv"},{'9',"wxyz"}};//MAP存储每个按键上的数字对应的字母

    vector<string> ans;
    string res;


//回溯题目需要好好联系
    void backtrack(string digits , int start){
        if (start == digits.size())
        {
            ans.push_back(res);
        }
        
        string temp = MAP[digits[start]];
        for (int i = 0; i < temp.size(); i++)
        {
            
            res += temp[i];
            backtrack(digits,start+1);
            res.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) {
        //回溯求解


        int n = digits.size();
        if (n == 0)
        {
            return {};
        }
        backtrack(digits,0);
        return ans;

    }
};
// @lc code=end

