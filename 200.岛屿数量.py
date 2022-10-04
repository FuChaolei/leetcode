#
# @lc app=leetcode.cn id=200 lang=python3
#
# [200] 岛屿数量
#
# https://leetcode.cn/problems/number-of-islands/description/
#
# algorithms
# Medium (58.67%)
# Likes:    1934
# Dislikes: 0
# Total Accepted:    563.6K
# Total Submissions: 960.4K
# Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
#
# 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
#
# 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
#
# 此外，你可以假设该网格的四条边均被水包围。
#
#
#
# 示例 1：
#
#
# 输入：grid = [
# ⁠ ["1","1","1","1","0"],
# ⁠ ["1","1","0","1","0"],
# ⁠ ["1","1","0","0","0"],
# ⁠ ["0","0","0","0","0"]
# ]
# 输出：1
#
#
# 示例 2：
#
#
# 输入：grid = [
# ⁠ ["1","1","0","0","0"],
# ⁠ ["1","1","0","0","0"],
# ⁠ ["0","0","1","0","0"],
# ⁠ ["0","0","0","1","1"]
# ]
# 输出：3
#
#
#
#
# 提示：
#
#
# m == grid.length
# n == grid[i].length
# 1
# grid[i][j] 的值为 '0' 或 '1'
#
#
#

# @lc code=start
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        def dfs(grid, i, j, m, n):
            if i < 0 or j < 0 or j >= m or i >= n or grid[i][j] == '0':
                return
            grid[i][j] = '0'
            dfs(grid, i-1, j, m, n)
            dfs(grid, i+1, j, m, n)
            dfs(grid, i, j-1, m, n)
            dfs(grid, i, j+1, m, n)
        n = len(grid)
        if n == 0:
            return 0
        m = len(grid[0])
        res = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == '1':
                    res += 1
                    dfs(grid, i, j, m, n)
        return res
# @lc code=end
