#
# @lc app=leetcode.cn id=78 lang=python3
#
# [78] 子集
#
# https://leetcode.cn/problems/subsets/description/
#
# algorithms
# Medium (80.85%)
# Likes:    1838
# Dislikes: 0
# Total Accepted:    540.8K
# Total Submissions: 668.8K
# Testcase Example:  '[1,2,3]'
#
# 给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
#
# 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
#
#
#
# 示例 1：
#
#
# 输入：nums = [1,2,3]
# 输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
#
#
# 示例 2：
#
#
# 输入：nums = [0]
# 输出：[[],[0]]
#
#
#
#
# 提示：
#
#
# 1
# -10
# nums 中的所有元素 互不相同
#
#
#

# @lc code=start
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []
        path = []

        def backtrace(nums, start):
            res.append(path[:])
            for i in range(start, len(nums)):
                path.append(nums[i])
                backtrace(nums, i+1)
                path.pop()
        backtrace(nums, 0)
        return res
# @lc code=end
