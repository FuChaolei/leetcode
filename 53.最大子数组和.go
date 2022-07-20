/*
 * @lc app=leetcode.cn id=53 lang=golang
 *
 * [53] 最大子数组和
 *
 * https://leetcode.cn/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (54.77%)
 * Likes:    5112
 * Dislikes: 0
 * Total Accepted:    1.1M
 * Total Submissions: 2M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 *
 * 子数组 是数组中的一个连续部分。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
 * 输出：6
 * 解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1]
 * 输出：1
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [5,4,-1,7,8]
 * 输出：23
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 *
 *
 *
 *
 * 进阶：如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的 分治法 求解。
 *
 */

// @lc code=start
//贪心
// func maxSubArray(nums []int) int {
// 	res := nums[0]
// 	tmp := 0
// 	for i := 0; i < len(nums); i++ {
// 		tmp += nums[i]
// 		if tmp > res {
// 			res = tmp
// 		}
// 		if tmp < 0 {
// 			tmp = 0
// 		}
// 	}
// 	return res
// }

//动态规划
func maxSubArray(nums []int) int {
	n := len(nums)
	db := make([]int, n)
	db[0] = nums[0]
	res := nums[0]
	for i := 1; i < n; i++ {
		db[i] = max(nums[i], db[i-1]+nums[i])
		res = max(res, db[i])
	}
	return res
}
func max(a int, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

// @lc code=end

