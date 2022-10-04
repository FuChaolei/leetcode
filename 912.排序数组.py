#
# @lc app=leetcode.cn id=912 lang=python3
#
# [912] 排序数组
#
# https://leetcode.cn/problems/sort-an-array/description/
#
# algorithms
# Medium (55.13%)
# Likes:    698
# Dislikes: 0
# Total Accepted:    457K
# Total Submissions: 829.3K
# Testcase Example:  '[5,2,3,1]'
#
# 给你一个整数数组 nums，请你将该数组升序排列。
#
#
#
#
#
#
# 示例 1：
#
#
# 输入：nums = [5,2,3,1]
# 输出：[1,2,3,5]
#
#
# 示例 2：
#
#
# 输入：nums = [5,1,1,2,0,0]
# 输出：[0,0,1,1,2,5]
#
#
#
#
# 提示：
#
#
# 1 <= nums.length <= 5 * 10^4
# -5 * 10^4 <= nums[i] <= 5 * 10^4
#
#
#

# @lc code=start
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        self.qsort(nums, 0, n-1)
        return nums

    def qsort(self, nums, l, r):
        if l >= r:
            return
        if r-l <= 15:
            self.insertsort(nums, l, r)
            return
        m = random.randint(l, r)
        nums[m], nums[l] = nums[l], nums[m]
        x, y = l, r
        tmp = nums[l]
        i = x+1
        while i <= y:
            if nums[i] < tmp:
                nums[i], nums[x] = nums[x], nums[i]
                i += 1
                x += 1
            elif nums[i] == tmp:
                i += 1
            else:
                nums[i], nums[y] = nums[y], nums[i]
                y -= 1
        self.qsort(nums, l, x-1)
        self.qsort(nums, y+1, r)

    def insertsort(self, nums, l, r):
        for i in range(l, r+1):
            j = i-1
            t = nums[i]
            while j >= l and nums[j] >= t:
                nums[j+1] = nums[j]
                j -= 1
            nums[j+1] = t
# @lc code=end
