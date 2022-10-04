#
# @lc app=leetcode.cn id=5 lang=python3
#
# [5] 最长回文子串
#
# https://leetcode.cn/problems/longest-palindromic-substring/description/
#
# algorithms
# Medium (37.17%)
# Likes:    5773
# Dislikes: 0
# Total Accepted:    1.2M
# Total Submissions: 3.3M
# Testcase Example:  '"babad"'
#
# 给你一个字符串 s，找到 s 中最长的回文子串。
#
#
#
# 示例 1：
#
#
# 输入：s = "babad"
# 输出："bab"
# 解释："aba" 同样是符合题意的答案。
#
#
# 示例 2：
#
#
# 输入：s = "cbbd"
# 输出："bb"
#
#
#
#
# 提示：
#
#
# 1 <= s.length <= 1000
# s 仅由数字和英文字母组成
#
#
#

# @lc code=start
class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)

        def getlenth(l, r):
            while l >= 0 and r < n and s[l] == s[r]:
                l -= 1
                r += 1
            return r-l-1
        start = 0
        cur = 0
        lenth = 0
        for i in range(n):
            cur = max(getlenth(i, i), getlenth(i, i+1))
            if cur > lenth:
                lenth = cur
                start = i-(lenth-1)//2
        return s[start:start+lenth]

# @lc code=end
