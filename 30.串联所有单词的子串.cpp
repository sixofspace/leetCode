// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem30.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */ //https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/solution/ha-xi-yu-shuang-zhi-zhen-by-acvv_itdef-9lgb/
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
    vector<int> findSubstring(string s, vector<string>& words) {
        //暴力哈希求解
        vector<int> res;
        int wordnums = words.size();
        if (wordnums == 0 )
        {
            return res;
        }
        int wordLen = words[0].size();
        unordered_map<string , int> allwords;
        for(auto &w : words){
            allwords[w]++;
        }
        int a = 0;
        int b = 0;
        for (int  i = 0; i < s.size() - wordnums * wordLen + 1; i++)
        {
            unordered_map<string , int> hasword ;
            int num = 0 ;
            while ( num < wordnums)
            {
                string word = s.substr( i + num * wordLen , i + (num + 1)* wordLen );
                if (allwords.find(word) !=  allwords.end())
                {
                    hasword[word]++;
                    if (hasword.at(word) > allwords.at(word))
                    {
                        res.push_back(hasword.at(word));
                    }
                    res.push_back( allwords.at(word));
                }else{
                     break;
                }
                num++;
            }
            if (num == wordnums) {
                res.push_back(i);
            }
        }
        return res;



    }
};
// @lc code=end

