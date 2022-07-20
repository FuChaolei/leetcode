/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 *
 * https://leetcode.cn/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (54.77%)
 * Likes:    5112
 * Dislikes: 0
 * Total Accepted:    1.1M
 * Total Submissions: 2M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 *
 * 子数组 是数组中的一个连续部分。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
 * 输出：6
 * 解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1]
 * 输出：1
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [5,4,-1,7,8]
 * 输出：23
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 *
 *
 *
 *
 * 进阶：如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的 分治法 求解。
 *
 */

// @lc code=start
//暴力超时
// class Solution
// {
// public:
//     int maxSubArray(vector<int> &nums)
//     {
//         int count = nums.size();
//         int max = nums[0];
//         for (size_t i = 0; i < count; i++)
//         {
//             int tmp = 0;
//             for (size_t j = i; j < count; j++)
//             {
//                 tmp += nums[j];
//                 if (tmp > max)
//                 {
//                     max = tmp;
//                 }
//             }
//         }
//         return max;
//     }
// };
//动态规划
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int res = nums[0];
        int count = nums.size();
        vector<int> db(nums.size());
        db[0] = nums[0];
        for (size_t i = 1; i < count; i++)
        {
            db[i] = max(db[i - 1] + nums[i], nums[i]);
            if (db[i] > res)
            {
                res = db[i];
            }
        }
        return res;
    }
};
//贪心
// class Solution
// {
// public:
//     int maxSubArray(vector<int> &nums)
//     {
//         int res = INT_MIN;
//         int count = nums.size();
//         int tmp = 0;
//         for (size_t i = 0; i < count; i++)
//         {
//             tmp += nums[i];
//             res = max(res, tmp);
//             if (tmp < 0)
//             {
//                 tmp = 0;
//             }
//         }
//         return res;
//     }
// };
// @lc code=end
