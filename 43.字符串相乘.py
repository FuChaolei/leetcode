#
# @lc app=leetcode.cn id=43 lang=python3
#
# [43] 字符串相乘
#
# https://leetcode.cn/problems/multiply-strings/description/
#
# algorithms
# Medium (44.71%)
# Likes:    1079
# Dislikes: 0
# Total Accepted:    267K
# Total Submissions: 597.5K
# Testcase Example:  '"2"\n"3"'
#
# 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
#
# 注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。
#
#
#
# 示例 1:
#
#
# 输入: num1 = "2", num2 = "3"
# 输出: "6"
#
# 示例 2:
#
#
# 输入: num1 = "123", num2 = "456"
# 输出: "56088"
#
#
#
# 提示：
#
#
# 1 <= num1.length, num2.length <= 200
# num1 和 num2 只能由数字组成。
# num1 和 num2 都不包含任何前导零，除了数字0本身。
#
#
#

# @lc code=start
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1=="0" or num2=="0":
            return "0"
        n,m=len(num1),len(num2)
        tmp = [0]*(m+n)
        for i in range(n-1,-1,-1):
            for j in range(m-1,-1,-1):
                tmp[i+j+1]+=(ord(num1[i])-ord('0'))*(ord(num2[j])-ord('0'))
        t = 0
        for i in range(m+n-1,-1,-1):
            t+=tmp[i]
            tmp[i] = t%10
            t//=10
        res = ""
        if tmp[0]!=0:
            for i in range(0,m+n):
                res+=str(tmp[i])
        else:
            for i in range(1,m+n):
                res+=str(tmp[i])
        return res
# @lc code=end

