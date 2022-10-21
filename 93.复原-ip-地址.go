/*
 * @lc app=leetcode.cn id=93 lang=golang
 *
 * [93] 复原 IP 地址
 *
 * https://leetcode-cn.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (53.87%)
 * Likes:    679
 * Dislikes: 0
 * Total Accepted:    150.8K
 * Total Submissions: 279.8K
 * Testcase Example:  '"25525511135"'
 *
 * 给定一个只包含数字的字符串，用以表示一个 IP 地址，返回所有可能从 s 获得的 有效 IP 地址 。你可以按任何顺序返回答案。
 *
 * 有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。
 *
 * 例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312"
 * 和 "192.168@1.1" 是 无效 IP 地址。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "25525511135"
 * 输出：["255.255.11.135","255.255.111.35"]
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "0000"
 * 输出：["0.0.0.0"]
 *
 *
 * 示例 3：
 *
 *
 * 输入：s = "1111"
 * 输出：["1.1.1.1"]
 *
 *
 * 示例 4：
 *
 *
 * 输入：s = "010010"
 * 输出：["0.10.0.10","0.100.1.0"]
 *
 *
 * 示例 5：
 *
 *
 * 输入：s = "101023"
 * 输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0
 * s 仅由数字组成
 *
 *
 */

// @lc code=start
func restoreIpAddresses(s string) []string {
	res := []string{}
	if len(s) > 12 {
		return res
	}
	var dfs func(string, int, int)
	dfs = func(s string, i int, p int) {
		if p == 3 {
			if check(s, i, len(s)-1) {
				res = append(res, s)
			}
			return
		}
		for j := i; j < len(s); j++ {
			if check(s, i, j) {
				p++
				s1 := s[:j+1]
				s2 := s[j+1 : len(s)]
				s = s1 + "." + s2
				dfs(s, j+2, p)
				s = s1 + s2
				p--
			} else {
				break
			}
		}
	}
	dfs(s, 0, 0)
	return res
}
func check(s string, b int, e int) bool {
	if b > e {
		return false
	}
	if s[b] == '0' && e > b {
		return false
	}
	if e-b >= 3 {
		return false
	}
	for i := b; i <= e; i++ {
		if s[i] > '9' || s[i] < '0' {
			return false
		}
	}
	tmp, _ := strconv.Atoi(s[b : e+1])
	if tmp > 255 {
		return false
	}
	return true
}

// @lc code=end

