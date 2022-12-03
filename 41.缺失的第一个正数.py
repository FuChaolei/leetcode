#
# @lc app=leetcode.cn id=41 lang=python3
#
# [41] 缺失的第一个正数
#
# https://leetcode.cn/problems/first-missing-positive/description/
#
# algorithms
# Hard (42.81%)
# Likes:    1679
# Dislikes: 0
# Total Accepted:    266.7K
# Total Submissions: 623.1K
# Testcase Example:  '[1,2,0]'
#
# 给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
# 请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
#
#
#
# 示例 1：
#
#
# 输入：nums = [1,2,0]
# 输出：3
#
#
# 示例 2：
#
#
# 输入：nums = [3,4,-1,1]
# 输出：2
#
#
# 示例 3：
#
#
# 输入：nums = [7,8,9,11,12]
# 输出：1
#
#
#
#
# 提示：
#
#
# 1
# -2^31
#
#
#

# @lc code=start
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n=len(nums)
        for i in range(n):
            while nums[i]>0 and nums[i]<=n and nums[nums[i]-1]!=nums[i]:
                tmp = nums[i]-1
                nums[i],nums[tmp]=nums[tmp],nums[i]
        for i in range(n):
            if i+1!=nums[i]:
                return i+1
        return n+1
# @lc code=end

