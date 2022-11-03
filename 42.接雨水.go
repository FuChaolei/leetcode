/*
 * @lc app=leetcode.cn id=42 lang=golang
 *
 * [42] 接雨水
 *
 * https://leetcode.cn/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (62.19%)
 * Likes:    3914
 * Dislikes: 0
 * Total Accepted:    598.5K
 * Total Submissions: 962.3K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出：6
 * 解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。
 *
 *
 * 示例 2：
 *
 *
 * 输入：height = [4,2,0,3,2,5]
 * 输出：9
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == height.length
 * 1 <= n <= 2 * 10^4
 * 0 <= height[i] <= 10^5
 *
 *
 */

// @lc code=start
func trap(height []int) int {
	if len(height) == 0 {
		return 0
	}
	res := 0
	l, r := 0, len(height)-1
	max_l, max_r := height[0], height[r]
	for l < r {
		if max_l < max_r {
			res += max_l - height[l]
			l++
			max_l = max(max_l, height[l])
		} else {
			res += max_r - height[r]
			r--
			max_r = max(max_r, height[r])
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

