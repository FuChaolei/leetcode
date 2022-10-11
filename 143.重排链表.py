#
# @lc app=leetcode.cn id=143 lang=python3
#
# [143] 重排链表
#
# https://leetcode.cn/problems/reorder-list/description/
#
# algorithms
# Medium (64.37%)
# Likes:    1055
# Dislikes: 0
# Total Accepted:    215.3K
# Total Submissions: 334.4K
# Testcase Example:  '[1,2,3,4]'
#
# 给定一个单链表 L 的头节点 head ，单链表 L 表示为：
#
#
# L0 → L1 → … → Ln - 1 → Ln
#
#
# 请将其重新排列后变为：
#
#
# L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
#
# 不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
#
#
#
# 示例 1：
#
#
#
#
# 输入：head = [1,2,3,4]
# 输出：[1,4,2,3]
#
# 示例 2：
#
#
#
#
# 输入：head = [1,2,3,4,5]
# 输出：[1,5,2,4,3]
#
#
#
# 提示：
#
#
# 链表的长度范围为 [1, 5 * 10^4]
# 1 <= node.val <= 1000
#
#
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        if head == None or head.next == None:
            return
        mid = self.half(head)
        l2 = mid.next
        l2 = self.reverse(l2)
        l1 = head
        mid.next = None
        self.merge(l1, l2)

    def half(self, head):
        s = head
        f = head
        while f and f.next:
            f = f.next.next
            s = s.next
        return s

    def reverse(self, head):
        if not head or not head.next:
            return head
        p = None
        cur = head
        while cur:
            next = cur.next
            cur.next = p
            p = cur
            cur = next
        return p

    def merge(self, l1, l2):
        l1tmp = l1
        l2tmp = l2
        while l1 and l2:
            l1tmp = l1.next
            l2tmp = l2.next
            l1.next = l2
            l1 = l1tmp
            l2.next = l1
            l2 = l2tmp
# @lc code=end
