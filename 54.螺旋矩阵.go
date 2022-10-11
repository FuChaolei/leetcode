/*
 * @lc app=leetcode.cn id=54 lang=golang
 *
 * [54] 螺旋矩阵
 *
 * https://leetcode.cn/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (49.15%)
 * Likes:    1228
 * Dislikes: 0
 * Total Accepted:    314.1K
 * Total Submissions: 639.1K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[1,2,3,6,9,8,7,4,5]
 *
 *
 * 示例 2：
 *
 *
 * 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * 输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == matrix.length
 * n == matrix[i].length
 * 1
 * -100
 *
 *
 */

// @lc code=start
func spiralOrder(matrix [][]int) []int {
	res := []int{}
	if len(matrix) == 0 {
		return res
	}
	l, r, t, b := 0, len(matrix[0])-1, 0, len(matrix)-1
	for true {
		for i := l; i <= r; i++ {
			res = append(res, matrix[l][i])
		}
		t += 1
		if b < t {
			break
		}
		for i := t; i <= b; i++ {
			res = append(res, matrix[i][r])
		}
		r -= 1
		if r < l {
			break
		}
		for i := r; i >= l; i-- {
			res = append(res, matrix[b][i])
		}
		b -= 1
		if b < t {
			break
		}
		for i := b; i >= t; i-- {
			res = append(res, matrix[i][l])
		}
		l += 1
		if r < l {
			break
		}
	}
	return res
}

// @lc code=end

