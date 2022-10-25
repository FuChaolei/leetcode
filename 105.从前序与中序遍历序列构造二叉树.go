/*
 * @lc app=leetcode.cn id=105 lang=golang
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (71.38%)
 * Likes:    1764
 * Dislikes: 0
 * Total Accepted:    430K
 * Total Submissions: 602.5K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder
 * 是同一棵树的中序遍历，请构造二叉树并返回其根节点。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * 输出: [3,9,20,null,null,15,7]
 *
 *
 * 示例 2:
 *
 *
 * 输入: preorder = [-1], inorder = [-1]
 * 输出: [-1]
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= preorder.length <= 3000
 * inorder.length == preorder.length
 * -3000 <= preorder[i], inorder[i] <= 3000
 * preorder 和 inorder 均 无重复 元素
 * inorder 均出现在 preorder
 * preorder 保证 为二叉树的前序遍历序列
 * inorder 保证 为二叉树的中序遍历序列
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
func buildTree(preorder []int, inorder []int) *TreeNode {
	index := make(map[int]int)
	n := len(preorder)

	var dfs func([]int, []int, int, int, int, int) *TreeNode
	dfs = func(preorder []int, inorder []int, pre_left int, pre_right int, in_left int, in_right int) *TreeNode {
		if pre_left > pre_right {
			return nil
		}
		root := &TreeNode{preorder[pre_left], nil, nil}
		in_pos := index[preorder[pre_left]]
		len := in_pos - in_left
		root.Left = dfs(preorder, inorder, pre_left+1, pre_left+len, in_left, in_pos-1)
		root.Right = dfs(preorder, inorder, pre_left+len+1, pre_right, in_pos+1, in_right)
		return root
	}
	for i := 0; i < n; i++ {
		index[inorder[i]] = i
	}
	return dfs(preorder, inorder, 0, n-1, 0, n-1)
}

// @lc code=end

