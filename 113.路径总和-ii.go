/*
 * @lc app=leetcode.cn id=113 lang=golang
 *
 * [113] 路径总和 II
 *
 * https://leetcode.cn/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (63.22%)
 * Likes:    856
 * Dislikes: 0
 * Total Accepted:    304.8K
 * Total Submissions: 482.2K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * 给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。
 *
 * 叶子节点 是指没有子节点的节点。
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
 * 输出：[[5,4,11,2],[5,8,4,5]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [1,2,3], targetSum = 5
 * 输出：[]
 *
 *
 * 示例 3：
 *
 *
 * 输入：root = [1,2], targetSum = 0
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点总数在范围 [0, 5000] 内
 * -1000
 * -1000
 *
 *
 *
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func pathSum(root *TreeNode, targetSum int) [][]int {
	res := [][]int{}
	path := []int{}
	if root == nil {
		return res
	}
	path = append(path, root.Val)
	var backtrace func(*TreeNode, int)
	backtrace = func(root *TreeNode, targetSum int) {
		if root == nil {
			return
		}
		if targetSum == 0 && root.Left == nil && root.Right == nil {
			tmp := make([]int, len(path))
			copy(tmp, path)
			res = append(res, tmp)
			return
		}
		if targetSum != 0 && root.Left == nil && root.Right == nil {
			return
		}
		if root.Left != nil {
			path = append(path, root.Left.Val)
			targetSum -= root.Left.Val
			backtrace(root.Left, targetSum)
			targetSum += root.Left.Val
			path = path[:len(path)-1]
		}
		if root.Right != nil {
			path = append(path, root.Right.Val)
			targetSum -= root.Right.Val
			backtrace(root.Right, targetSum)
			targetSum += root.Right.Val
			path = path[:len(path)-1]
		}
		return
	}
	backtrace(root, targetSum-root.Val)
	return res
}

// @lc code=end

