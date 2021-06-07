/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
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
    void backtrack(vector<string>& ans, string& cur, int open, int close, int n) {
        if ( cur.size() == n * 2)
        {
            ans.push_back(cur);
            return ;
        }
        if ( open < n)
        {
            cur.push_back('(');
            backtrack(ans,cur,open + 1 ,close,n);
            cur.pop_back();
        }

        if (close < open)
        {
            cur.push_back(')');
            backtrack(ans,cur,open,close + 1,n);
            cur.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        backtrack(result , current , 0,0,n);
        return result;
    }
};
// @lc code=end


// void run(当前状态)
// {
//     if(当前状态的边界)
//     {
//         if(当前状态为最佳的目标形态)
//             记下最优结果;
//             return;
//     }
//     for(int i = 算符最小值; i <= 算符最大值 ; ++i)
//     {
//         算符i作用于当前状态，扩展出一个子状态;
//         if(子状态满足约束条件)&&(子状态满足最优性要求)
//             run(子状态);
//     }
// }
// 这只是一个大致的轮廓，需要根据试题要求，做适当的调整。例如，对非最优性问题，可略去当前状态是否为最佳目标状态和扩展出的子状态是否满足最优性要求的判断，若是求最长路径，可略去边界条件的判断，等等，但是在使用回溯法解题时，一般需要结合题意考虑如下因素

// 一：定义状态：即描述问题求解过程中每一步的情况。为了精简程序，增加可读性，我们一般将参与子状态扩展运算的变量组合称当前状态列入值参或局部变量，以便回溯时能恢复递归前的状态，重新计算下一条路径。若这些参数的存储值大（例如数组），为避免内存溢出，则必须将其设为全局变量，且会回溯前恢复其递归前的值。

// 二 ：边界条件：即在什么情况下，程序不在递归下去，如果是求满足某个特定条件的最佳路径，则当前状态到达边界时不一定意味着此时就是最佳的目标状态，因此须增添判别最优目标状态的条件。

// 三：搜索范围：若当前状态不满足边界条件，则扩展子状态。这种情况下，应如何设计扩展子状态的算符值范围 in other words 如何设定for循环中的初始值和终止值？

// 四：约束条件和最优性要求：扩展出的子状态应该满足什么条件递归才能继续下去。如果是求满足某个特定条件的一条最佳路径，那么扩展出某子状态后是否继续递归搜索下去，不仅取决于子状态是否满足约束条件，而且还取决取子状态是否满足最优性的要求。
 