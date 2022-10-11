/*
 * @lc app=leetcode.cn id=143 lang=golang
 *
 * [143] 重排链表
 *
 * https://leetcode.cn/problems/reorder-list/description/
 *
 * algorithms
 * Medium (64.37%)
 * Likes:    1055
 * Dislikes: 0
 * Total Accepted:    215.3K
 * Total Submissions: 334.4K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个单链表 L 的头节点 head ，单链表 L 表示为：
 *
 *
 * L0 → L1 → … → Ln - 1 → Ln
 *
 *
 * 请将其重新排列后变为：
 *
 *
 * L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
 *
 * 不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：head = [1,2,3,4]
 * 输出：[1,4,2,3]
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入：head = [1,2,3,4,5]
 * 输出：[1,5,2,4,3]
 *
 *
 *
 * 提示：
 *
 *
 * 链表的长度范围为 [1, 5 * 10^4]
 * 1 <= node.val <= 1000
 *
 *
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reorderList(head *ListNode) {
	if head == nil || head.Next == nil {
		return
	}
	mid := half(head)
	l2 := mid.Next
	l2 = reverse(l2)
	mid.Next = nil
	l1 := head
	merge(l1, l2)
}
func half(head *ListNode) *ListNode {
	s, f := head, head
	for f != nil && f.Next != nil {
		f = f.Next.Next
		s = s.Next
	}
	return s
}
func reverse(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	var p *ListNode
	cur := head
	for cur != nil {
		next := cur.Next
		cur.Next = p
		p = cur
		cur = next
	}
	return p
}
func merge(l1 *ListNode, l2 *ListNode) {
	l1tmp := l1
	l2tmp := l2
	for l1 != nil && l2 != nil {
		l1tmp = l1.Next
		l1.Next = l2
		l1 = l1tmp
		l2tmp = l2.Next
		l2.Next = l1
		l2 = l2tmp
	}
}

// @lc code=end

