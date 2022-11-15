/*
 * @lc app=leetcode.cn id=4 lang=golang
 *
 * [4] 寻找两个正序数组的中位数
 *
 * https://leetcode.cn/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (41.56%)
 * Likes:    6075
 * Dislikes: 0
 * Total Accepted:    844.7K
 * Total Submissions: 2M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
 *
 * 算法的时间复杂度应该为 O(log (m+n)) 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums1 = [1,3], nums2 = [2]
 * 输出：2.00000
 * 解释：合并数组 = [1,2,3] ，中位数 2
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums1 = [1,2], nums2 = [3,4]
 * 输出：2.50000
 * 解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
 *
 *
 *
 *
 *
 *
 * 提示：
 *
 *
 * nums1.length == m
 * nums2.length == n
 * 0 <= m <= 1000
 * 0 <= n <= 1000
 * 1 <= m + n <= 2000
 * -10^6 <= nums1[i], nums2[i] <= 10^6
 *
 *
 */

// @lc code=start
func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	n1 := len(nums1)
	n2 := len(nums2)
	if n2 < n1 {
		return findMedianSortedArrays(nums2, nums1)
	}
	l := 0
	r := n1
	k := (n1 + n2 + 1) / 2
	for l < r {
		m1 := l + (r-l)/2
		m2 := k - m1
		if nums1[m1] < nums2[m2-1] {
			l = m1 + 1
		} else {
			r = m1
		}
	}
	m1 := l
	m2 := k - l
	c1 := 0
	a, b := 0, 0
	if m1 == 0 {
		a = math.MinInt32
	} else {
		a = nums1[m1-1]
	}
	if m2 == 0 {
		b = math.MinInt32
	} else {
		b = nums2[m2-1]
	}
	c1 = max(a, b)
	if (n1+n2)%2 == 1 {
		return float64(c1)
	}
	c2 := 0
	if m1 == n1 {
		a = math.MaxInt32
	} else {
		a = nums1[m1]
	}
	if m2 == n2 {
		b = math.MaxInt32
	} else {
		b = nums2[m2]
	}
	c2 = min(a, b)
	return float64(c1+c2) / 2
}
func min(a int, b int) int {
	if a < b {
		return a
	}
	return b
}
func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

// @lc code=end

