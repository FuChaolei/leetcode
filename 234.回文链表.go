/*
 * @lc app=leetcode.cn id=234 lang=golang
 *
 * [234] 回文链表
 *
 * https://leetcode.cn/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (52.33%)
 * Likes:    1483
 * Dislikes: 0
 * Total Accepted:    490.3K
 * Total Submissions: 936.7K
 * Testcase Example:  '[1,2,2,1]'
 *
 * 给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：head = [1,2,2,1]
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 * 输入：head = [1,2]
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点数目在范围[1, 10^5] 内
 * 0 <= Node.val <= 9
 *
 *
 *
 *
 * 进阶：你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
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
func reverse(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	var pre *ListNode = nil
	cur := head
	for cur != nil {
		tmp := cur.Next
		cur.Next = pre
		pre = cur
		cur = tmp
	}
	return pre
}
func sf_ptr(head *ListNode) *ListNode {
	s, f := head, head
	if f == nil {
		return f
	}
	for f.Next != nil && f.Next.Next != nil {
		s = s.Next
		f = f.Next.Next
	}
	return s
}
func isPalindrome(head *ListNode) bool {
	if head == nil {
		return true
	}
	halfhead := sf_ptr(head)
	tailhead := reverse(halfhead.Next)
	fhead := head
	shead := tailhead
	res := true
	for res && shead != nil {
		if shead.Val != fhead.Val {
			res = false
		}
		shead = shead.Next
		fhead = fhead.Next
	}
	halfhead.Next = reverse(tailhead)
	return res
}

// @lc code=end

