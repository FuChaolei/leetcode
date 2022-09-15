/*
 * @lc app=leetcode.cn id=557 lang=golang
 *
 * [557] 反转字符串中的单词 III
 *
 * https://leetcode.cn/problems/reverse-words-in-a-string-iii/description/
 *
 * algorithms
 * Easy (74.13%)
 * Likes:    482
 * Dislikes: 0
 * Total Accepted:    266.6K
 * Total Submissions: 359.6K
 * Testcase Example:  `"Let's take LeetCode contest"`
 *
 * 给定一个字符串 s ，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "Let's take LeetCode contest"
 * 输出："s'teL ekat edoCteeL tsetnoc"
 *
 *
 * 示例 2:
 *
 *
 * 输入： s = "God Ding"
 * 输出："doG gniD"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 5 * 10^4
 * s 包含可打印的 ASCII 字符。
 * s 不包含任何开头或结尾空格。
 * s 里 至少 有一个词。
 * s 中的所有单词都用一个空格隔开。
 *
 *
 */

// @lc code=start
func reverseWords(s string) string {
	i,n:=0,len(s)
	res := []byte{}
	for i<n {
		fmt.Println(i)
		start := i
		for i<n && s[i]!=' ' {
			i++
		}
		for p:=start;p<i;p++ {
			res = append(res,s[i-p-1+start])
		}
		for i<n&&s[i]==' ' {
			res = append(res,' ')
			i++
		}
	}
	return string(res)
}
// @lc code=end

