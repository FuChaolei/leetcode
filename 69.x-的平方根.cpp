/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 *
 * https://leetcode.cn/problems/sqrtx/description/
 *
 * algorithms
 * Easy (38.82%)
 * Likes:    1118
 * Dislikes: 0
 * Total Accepted:    602.8K
 * Total Submissions: 1.6M
 * Testcase Example:  '4'
 *
 * 给你一个非负整数 x ，计算并返回 x 的 算术平方根 。
 *
 * 由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。
 *
 * 注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：x = 4
 * 输出：2
 *
 *
 * 示例 2：
 *
 *
 * 输入：x = 8
 * 输出：2
 * 解释：8 的算术平方根是 2.82842..., 由于返回类型是整数，小数部分将被舍去。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= x <= 2^31 - 1
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int mySqrt(int x)
    {
        int l = 0, r = x, res = 0;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if ((long long)mid * mid < x)
            {
                res = mid;
                l = l + 1;
            }
            else if ((long long)mid * mid == x)
            {
                return mid;
            }
            else
            {
                r = mid - 1;
            }
        }
        return res;
    }
};
// @lc code=end
