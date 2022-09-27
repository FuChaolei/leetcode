#
# @lc app=leetcode.cn id=215 lang=python3
#
# [215] 数组中的第K个最大元素
#
# https://leetcode.cn/problems/kth-largest-element-in-an-array/description/
#
# algorithms
# Medium (64.50%)
# Likes:    1890
# Dislikes: 0
# Total Accepted:    747.2K
# Total Submissions: 1.2M
# Testcase Example:  '[3,2,1,5,6,4]\n2'
#
# 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
#
# 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
#
# 你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。
#
#
#
# 示例 1:
#
#
# 输入: [3,2,1,5,6,4], k = 2
# 输出: 5
#
#
# 示例 2:
#
#
# 输入: [3,2,3,1,2,4,5,5,6], k = 4
# 输出: 4
#
#
#
# 提示：
#
#
# 1 <= k <= nums.length <= 10^5
# -10^4 <= nums[i] <= 10^4
#
#
#

# @lc code=start
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        n = len(nums)
        def qsort(nums, l, r, k):
            m = random.randint(l, r)
            nums[l], nums[m] = nums[m], nums[l]
            x, y = l, r
            t = nums[l]
            while x < y:
                while nums[y] <= t and x < y:
                    y -= 1
                while nums[x] >= t and x < y:
                    x += 1
                nums[x], nums[y] = nums[y], nums[x]
            nums[l], nums[x] = nums[x], nums[l]
            if x == k-1:
                return nums[x]
            elif x > k-1:
                return qsort(nums, 0, x-1, k)
            else:
                return qsort(nums, x+1, r, k)
        return qsort(nums, 0, n-1, k)


# @lc code=end
