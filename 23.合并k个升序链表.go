/*
 * @lc app=leetcode.cn id=23 lang=golang
 *
 * [23] 合并K个升序链表
 *
 * https://leetcode.cn/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (57.31%)
 * Likes:    2233
 * Dislikes: 0
 * Total Accepted:    566.3K
 * Total Submissions: 987.2K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * 给你一个链表数组，每个链表都已经按升序排列。
 *
 * 请你将所有链表合并到一个升序链表中，返回合并后的链表。
 *
 *
 *
 * 示例 1：
 *
 * 输入：lists = [[1,4,5],[1,3,4],[2,6]]
 * 输出：[1,1,2,3,4,4,5,6]
 * 解释：链表数组如下：
 * [
 * ⁠ 1->4->5,
 * ⁠ 1->3->4,
 * ⁠ 2->6
 * ]
 * 将它们合并到一个有序链表中得到。
 * 1->1->2->3->4->4->5->6
 *
 *
 * 示例 2：
 *
 * 输入：lists = []
 * 输出：[]
 *
 *
 * 示例 3：
 *
 * 输入：lists = [[]]
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * k == lists.length
 * 0 <= k <= 10^4
 * 0 <= lists[i].length <= 500
 * -10^4 <= lists[i][j] <= 10^4
 * lists[i] 按 升序 排列
 * lists[i].length 的总和不超过 10^4
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
func mergeKLists(lists []*ListNode) *ListNode {
	var merge func([]*ListNode, int, int) *ListNode
	merge = func(lists []*ListNode, l int, r int) *ListNode {
		if l > r {
			return nil
		}
		if l == r {
			return lists[l]
		}
		if l+1 == r {
			return mergeTwo(lists[l], lists[r])
		}
		mid := l + (r-l)/2
		left := merge(lists, l, mid)
		right := merge(lists, mid+1, r)
		return mergeTwo(left, right)
	}
	return merge(lists, 0, len(lists)-1)
}
func mergeTwo(l1 *ListNode, l2 *ListNode) *ListNode {
	dummy := &ListNode{
		Val: 0,
	}
	cur := dummy
	for l1 != nil && l2 != nil {
		if l2.Val < l1.Val {
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
	return dummy.Next
}

// @lc code=end

