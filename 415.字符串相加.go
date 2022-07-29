/*
 * @lc app=leetcode.cn id=415 lang=golang
 *
 * [415] 字符串相加
 *
 * https://leetcode.cn/problems/add-strings/description/
 *
 * algorithms
 * Easy (54.93%)
 * Likes:    598
 * Dislikes: 0
 * Total Accepted:    219.5K
 * Total Submissions: 399.1K
 * Testcase Example:  '"11"\n"123"'
 *
 * 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。
 *
 * 你不能使用任何內建的用于处理大整数的库（比如 BigInteger）， 也不能直接将输入的字符串转换为整数形式。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：num1 = "11", num2 = "123"
 * 输出："134"
 *
 *
 * 示例 2：
 *
 *
 * 输入：num1 = "456", num2 = "77"
 * 输出："533"
 *
 *
 * 示例 3：
 *
 *
 * 输入：num1 = "0", num2 = "0"
 * 输出："0"
 *
 *
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= num1.length, num2.length <= 10^4
 * num1 和num2 都只包含数字 0-9
 * num1 和num2 都不包含任何前导零
 *
 *
 */

// @lc code=start
func addStrings(num1 string, num2 string) string {
	x := len(num1) - 1
	y := len(num2) - 1
	add := 0
	s := ""
	for x >= 0 || y >= 0 || add != 0 {
		var j, k int
		if x >= 0 {
			j = int(num1[x] - '0')
		} else {
			j = 0
		}
		if y >= 0 {
			k = int(num2[y] - '0')
		} else {
			k = 0
		}
		res := j + k + add
		s = strconv.Itoa(res%10) + s
		add = res / 10
		x = x - 1
		y = y - 1
	}
	return s
}

// @lc code=end

