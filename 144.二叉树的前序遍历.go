/*
 * @lc app=leetcode.cn id=144 lang=golang
 *
 * [144] 二叉树的前序遍历
 *
 * https://leetcode.cn/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Easy (71.21%)
 * Likes:    891
 * Dislikes: 0
 * Total Accepted:    682.8K
 * Total Submissions: 958.4K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [1,null,2,3]
 * 输出：[1,2,3]
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = []
 * 输出：[]
 *
 *
 * 示例 3：
 *
 *
 * 输入：root = [1]
 * 输出：[1]
 *
 *
 * 示例 4：
 *
 *
 * 输入：root = [1,2]
 * 输出：[1,2]
 *
 *
 * 示例 5：
 *
 *
 * 输入：root = [1,null,2]
 * 输出：[1,2]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目在范围 [0, 100] 内
 * -100
 *
 *
 *
 *
 * 进阶：递归算法很简单，你可以通过迭代算法完成吗？
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
// func preorderTraversal(root *TreeNode) []int {
// 	var res []int
// 	var preorder func(*TreeNode)
// 	preorder = func(node *TreeNode) {
// 		if node == nil {
// 			return
// 		}
// 		res = append(res,node.Val)
// 		preorder(node.Left)
// 		preorder(node.Right)
// 	}
// 	preorder(root)
// 	return res
// }
func preorderTraversal(root *TreeNode) []int {
	var res []int
	var st []*TreeNode
	if root == nil {
		return res
	}
	st = append(st, root)
	for len(st) > 0 {
		node := st[len(st)-1]
		st = st[:len(st)-1]
		res = append(res, node.Val)
		if node.Right != nil {
			st = append(st, node.Right)
		}
		if node.Left != nil {
			st = append(st, node.Left)
		}
	}
	return res
}

// @lc code=end

