/*
 * @lc app=leetcode.cn id=32 lang=golang
 *
 * [32] 最长有效括号
 *
 * https://leetcode.cn/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (37.02%)
 * Likes:    2098
 * Dislikes: 0
 * Total Accepted:    334.1K
 * Total Submissions: 902.5K
 * Testcase Example:  '"(()"'
 *
 * 给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "(()"
 * 输出：2
 * 解释：最长有效括号子串是 "()"
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = ")()())"
 * 输出：4
 * 解释：最长有效括号子串是 "()()"
 *
 *
 * 示例 3：
 *
 *
 * 输入：s = ""
 * 输出：0
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0
 * s[i] 为 '(' 或 ')'
 *
 *
 *
 *
 */

// @lc code=start
func longestValidParentheses(s string) int {
	res := 0
	l, r := 0, 0
	for i := 0; i < len(s); i++ {
		if s[i] == '(' {
			l++
		} else {
			r++
		}
		if l == r {
			res = max(res, l*2)
		} else if r > l {
			l = 0
			r = 0
		}
	}
	l = 0
	r = 0
	for i := len(s) - 1; i >= 0; i-- {
		if s[i] == '(' {
			l++
		} else {
			r++
		}
		if l == r {
			res = max(res, l*2)
		} else if r < l {
			l = 0
			r = 0
		}
	}
	return res
}
func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

// @lc code=end

