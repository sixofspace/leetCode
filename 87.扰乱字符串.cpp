/*
 * @lc app=leetcode.cn id=87 lang=cpp
 *
 * [87] 扰乱字符串
 */
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
private:
    int memo[30][30][31];
    string s1,s2;
public:
    bool checkIfSimilar(int i1, int i2 , int length){
        unordered_map<int , int> freq;
        for (int i = 0; i < i1 + length; i++)
        {
            ++freq[s1[i]];
        }
        for (int i = 0; i < i2 + length; i++)
        {
            ++freq[s2[i]];
        }
        if (any_of(freq.begin(), freq.end(), [](const auto& entry) {return entry.second != 0;})) {
            return false;
        }
        return true;

    }
    bool isScramble(string s1, string s2) {

    }
};
// @lc code=end

