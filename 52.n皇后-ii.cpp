/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution
{
public:
    int totalNQueens(int n)
    {
        int res = 0;
        // vector<vector<string>> res;
        vector<string> temp;
        unordered_set<int> colum;
        unordered_set<int> diag0;
        unordered_set<int> diag1;
        vector<int> queens = vector<int>(n, -1);
        backtracking(res, queens, 0, n, colum, diag0, diag1);
        return res;
    }

    void backtracking(int &res, vector<int> &queens, int rows, int n, unordered_set<int> &colum, unordered_set<int> &diag0, unordered_set<int> &diag1)
    {
        if (rows == n)
        {
            res++;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (colum.find(i) != colum.end())
                {
                    continue;
                }
                int diag0num = rows - i;
                if (diag0.find(diag0num) != diag0.end())
                {
                    continue;
                }
                int diag1num = rows + i;
                if (diag1.find(diag1num) != diag1.end())
                {
                    continue;
                }
                colum.emplace(i);
                diag0.emplace(diag0num);
                diag1.emplace(diag1num);
                queens[rows] = i;
                backtracking(res, queens, rows + 1, n, colum, diag0, diag1);
                queens[rows] = -1;
                colum.erase(i);
                diag0.erase(diag0num);
                diag1.erase(diag1num);
            }
        }
    }
};
// @lc code=end
