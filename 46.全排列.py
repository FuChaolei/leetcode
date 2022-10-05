#
# @lc app=leetcode.cn id=46 lang=python3
#
# [46] 全排列
#
# https://leetcode.cn/problems/permutations/description/
#
# algorithms
# Medium (78.76%)
# Likes:    2245
# Dislikes: 0
# Total Accepted:    735.4K
# Total Submissions: 933.7K
# Testcase Example:  '[1,2,3]'
#
# 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
#
#
#
# 示例 1：
#
#
# 输入：nums = [1,2,3]
# 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
#
#
# 示例 2：
#
#
# 输入：nums = [0,1]
# 输出：[[0,1],[1,0]]
#
#
# 示例 3：
#
#
# 输入：nums = [1]
# 输出：[[1]]
#
#
#
#
# 提示：
#
#
# 1 <= nums.length <= 6
# -10 <= nums[i] <= 10
# nums 中的所有整数 互不相同
#
#
#

# @lc code=start
# class Solution:
#     def permute(self, nums: List[int]) -> List[List[int]]:
#         n = len(nums)
#         used = [False]*n
#         res = []
#         path = []
#         def dfs():
#             if len(path) == len(nums):
#                 res.append(path)
#                 return
#             for i in range(n):
#                 if used[i]:
#                     continue
#                 used[i] = True
#                 path.append(nums[i])
#                 dfs(l+1, path)
#                 used[i] = False
#                 path = path[:-1]
#         dfs()
#         return res
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res, path, used = [], [], [False] * len(nums)

        def dfs() -> None:
            if len(path) == len(nums):
                res.append(path[:])
                return
            for i in range(len(nums)):
                if used[i]:
                    continue
                path.append(nums[i])
                used[i] = True
                dfs()
                path.pop()
                used[i] = False
        dfs()
        return res
# @lc code=end
