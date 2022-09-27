/*
 * @lc app=leetcode.cn id=215 lang=golang
 *
 * [215] 数组中的第K个最大元素
 *
 * https://leetcode.cn/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (64.50%)
 * Likes:    1890
 * Dislikes: 0
 * Total Accepted:    747.2K
 * Total Submissions: 1.2M
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
 *
 * 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 *
 * 你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: [3,2,1,5,6,4], k = 2
 * 输出: 5
 *
 *
 * 示例 2:
 *
 *
 * 输入: [3,2,3,1,2,4,5,5,6], k = 4
 * 输出: 4
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= k <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 *
 *
 */

// @lc code=start
func findKthLargest(nums []int, k int) int {
	n := len(nums)
	rand.Seed(time.Now().UnixNano())
	return qsort(nums, 0, n-1, k)
}
func qsort(nums []int, l int, r int, k int) int {
	m := rand.Intn(r-l+1) + l
	nums[l], nums[m] = nums[m], nums[l]
	t := nums[l]
	x, y := l, r
	for x < y {
		for nums[y] <= t && x < y {
			y--
		}
		for nums[x] >= t && x < y {
			x++
		}
		nums[x], nums[y] = nums[y], nums[x]
	}
	nums[l], nums[x] = nums[x], nums[l]
	if x == k-1 {
		return nums[x]
	} else if x > k-1 {
		return qsort(nums, l, x-1, k)
	} else {
		return qsort(nums, x+1, r, k)
	}
}

// @lc code=end

