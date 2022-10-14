/*
 * @lc app=leetcode.cn id=148 lang=golang
 *
 * [148] 排序链表
 *
 * https://leetcode.cn/problems/sort-list/description/
 *
 * algorithms
 * Medium (66.18%)
 * Likes:    1804
 * Dislikes: 0
 * Total Accepted:    352.7K
 * Total Submissions: 533.1K
 * Testcase Example:  '[4,2,1,3]'
 *
 * 给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
 *
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：head = [4,2,1,3]
 * 输出：[1,2,3,4]
 *
 *
 * 示例 2：
 *
 *
 * 输入：head = [-1,5,3,4,0]
 * 输出：[-1,0,3,4,5]
 *
 *
 * 示例 3：
 *
 *
 * 输入：head = []
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点的数目在范围 [0, 5 * 10^4] 内
 * -10^5 <= Node.val <= 10^5
 *
 *
 *
 *
 * 进阶：你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？
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
// func sortList(head *ListNode) *ListNode {
// 	if head == nil || head.Next == nil {
// 		return head
// 	}
// 	f := head.Next
// 	s := head
// 	for f != nil && f.Next != nil {
// 		s = s.Next
// 		f = f.Next.Next
// 	}
// 	mid := s.Next
// 	s.Next = nil
// 	return merge(sortList(head), sortList(mid))
// }
// func merge(l1 *ListNode, l2 *ListNode) *ListNode {
// 	dummy := &ListNode{
// 		Val:  0,
// 		Next: nil,
// 	}
// 	cur := dummy
// 	for l1 != nil && l2 != nil {
// 		if l1.Val > l2.Val {
// 			l1, l2 = l2, l1
// 		}
// 		cur.Next = l1
// 		l1 = l1.Next
// 		cur = cur.Next
// 	}
// 	if l1 != nil {
// 		cur.Next = l1
// 	}
// 	if l2 != nil {
// 		cur.Next = l2
// 	}
// 	return dummy.Next
// }

type pair struct {
	first  *ListNode
	second *ListNode
}

func sortList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	cur := head
	len := 0
	for cur != nil {
		len++
		cur = cur.Next
	}
	//fmt.Print(len)
	var l *ListNode
	var r *ListNode
	var tail *ListNode
	dummy := &ListNode{
		Val:  0,
		Next: head,
	}
	for i := 1; i < len; i <<= 1 {
		cur = dummy.Next
		tail = dummy
		for cur != nil {
			l = cur
			r = split(l, i)
			cur = split(r, i)
			merged := merge(l, r)
			tail.Next = merged.first
			tail = merged.second
		}
	}
	return dummy.Next
}
func split(head *ListNode, n int) *ListNode {

	for n > 1 && head != nil {
		n--
		head = head.Next
	}
	var res *ListNode
	if head != nil {
		res = head.Next
	} else {
		res = nil
	}
	if head != nil {
		head.Next = nil
	}
	return res
}
func merge(l1 *ListNode, l2 *ListNode) *pair {
	//fmt.Print(l1.Val,l2.Val)
	dummy := &ListNode{
		Val:  0,
		Next: nil,
	}
	cur := dummy
	for l1 != nil && l2 != nil {
		if l1.Val > l2.Val {
			l1, l2 = l2, l1
		}
		cur.Next = l1
		l1 = l1.Next
		cur = cur.Next
	}
	if l1 != nil {
		cur.Next = l1
	}
	if l2 != nil {
		cur.Next = l2
	}
	for cur.Next != nil {
		cur = cur.Next
	}
	res := &pair{
		first:  dummy.Next,
		second: cur,
	}
	return res
}

// @lc code=end

