// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem88.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
// @lc code=start
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {

        //还可以逆向双指针，原地排序
        vector<int> nums(m + n);
        int p1 = 0;
        int p2 = 0;
        for (int i = 0; i < m + n; i++)
        {
            if (p2 == n)
            {
                nums[i] = nums1[p1++];
            }
            else if (p1 == m)
            {
                nums[i] = nums2[p2++];
            }
            else if (nums1[p1] < nums2[p2])
            {
                nums[i] = nums1[p1++];
            }
            else
            {
                nums[i] = nums2[p2++];
            }
        }
        for (int i = 0; i < m + n; i++)
        {
            nums1[i] = nums[i];
        }
    }
};
// @lc code=end
