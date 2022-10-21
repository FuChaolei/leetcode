#
# @lc app=leetcode.cn id=93 lang=python3
#
# [93] 复原 IP 地址
#
# https://leetcode.cn/problems/restore-ip-addresses/description/
#
# algorithms
# Medium (57.33%)
# Likes:    1051
# Dislikes: 0
# Total Accepted:    281.3K
# Total Submissions: 490.4K
# Testcase Example:  '"25525511135"'
#
# 有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。
#
#
# 例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312"
# 和 "192.168@1.1" 是 无效 IP 地址。
#
#
# 给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。你 不能
# 重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。
#
#
#
# 示例 1：
#
#
# 输入：s = "25525511135"
# 输出：["255.255.11.135","255.255.111.35"]
#
#
# 示例 2：
#
#
# 输入：s = "0000"
# 输出：["0.0.0.0"]
#
#
# 示例 3：
#
#
# 输入：s = "101023"
# 输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
#
#
#
#
# 提示：
#
#
# 1 <= s.length <= 20
# s 仅由数字组成
#
#
#

# @lc code=start
class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        res = []

        def check(s, b, e):
            if b > e:
                return False
            if e-b >= 3:
                return False
            if s[b] == '0' and e > b:
                return False
            if not s[b:e+1].isdigit():
                return False
            if int(s[b:e+1]) > 255:
                return False
            return True

        def backtrack(s, i, p):
            if p == 3:
                if check(s, i, len(s)-1):
                    res.append(s)
                return
            for j in range(i, len(s)):
                if check(s, i, j):
                    p += 1
                    t1 = s[:j+1]
                    t2 = s[j+1:]
                    s = t1 + "." + t2
                    backtrack(s, j+2, p)
                    s = t1 + t2
                    p -= 1
                else:
                    break
        backtrack(s, 0, 0)
        return res
# @lc code=end
