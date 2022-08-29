#
# @lc app=leetcode.cn id=7 lang=python3
#
# [7] 整数反转
#
# https://leetcode.cn/problems/reverse-integer/description/
#
# algorithms
# Medium (35.37%)
# Likes:    3609
# Dislikes: 0
# Total Accepted:    1.1M
# Total Submissions: 3M
# Testcase Example:  '123'
#
# 给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。
#
# 如果反转后整数超过 32 位的有符号整数的范围 [−2^31,  2^31 − 1] ，就返回 0。
# 假设环境不允许存储 64 位整数（有符号或无符号）。
#
#
#
# 示例 1：
#
#
# 输入：x = 123
# 输出：321
#
#
# 示例 2：
#
#
# 输入：x = -123
# 输出：-321
#
#
# 示例 3：
#
#
# 输入：x = 120
# 输出：21
#
#
# 示例 4：
#
#
# 输入：x = 0
# 输出：0
#
#
#
#
# 提示：
#
#
# -2^31
#
#
#

# @lc code=start


class Solution:
    def reverse(self, x: int) -> int:
        res = 0
        maxint = 2**31-1
        minint = -2**31
        while x != 0:
            if res > maxint//10 or res < minint//10+1:
                # print(res)
                return 0
            tmp = x % 10
            if tmp > 0 and x < 0:
                tmp -= 10
            x = (x-tmp)//10
            res = res*10+tmp
        return res
# @lc code=end
