/*
 * @lc app=leetcode.cn id=912 lang=golang
 *
 * [912] 排序数组
 *
 * https://leetcode.cn/problems/sort-an-array/description/
 *
 * algorithms
 * Medium (55.16%)
 * Likes:    697
 * Dislikes: 0
 * Total Accepted:    456.7K
 * Total Submissions: 828.6K
 * Testcase Example:  '[5,2,3,1]'
 *
 * 给你一个整数数组 nums，请你将该数组升序排列。
 *
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [5,2,3,1]
 * 输出：[1,2,3,5]
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [5,1,1,2,0,0]
 * 输出：[0,0,1,1,2,5]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 5 * 10^4
 * -5 * 10^4 <= nums[i] <= 5 * 10^4
 *
 *
 */

// @lc code=start
func sortArray(nums []int) []int {
	n := len(nums)
	rand.Seed(time.Now().UnixNano())
	qsort(nums, 0, n-1)
	return nums
}
func qsort(nums []int, l int, r int) {
	if l>=r {
		return
	}
	if r-l<=15 {
		insersort(nums,l,r)
		return
	}
	m := rand.Intn(r-l+1) + l
	nums[l], nums[m] = nums[m], nums[l]
	x := l
	y := r
	t := nums[x]
	i := l + 1
	for i <= y {
		if nums[i] < t {
			nums[i], nums[x] = nums[x], nums[i]
			i++
			x++
		} else if nums[i] == t {
			i++
		} else {
			nums[i], nums[y] = nums[y], nums[i]
			y--
		}
	}
	qsort(nums, l, x-1)
	qsort(nums, y+1, r)
}
func insersort(nums []int,l int,r int){
	for i:=l;i<=r;i++ {
		j := i-1
		tmp:=nums[i]
		for j>=l && nums[j]>=tmp {
			nums[j+1] = nums[j]
			j--
		}
		nums[j+1]=tmp
	}
}
// @lc code=end

