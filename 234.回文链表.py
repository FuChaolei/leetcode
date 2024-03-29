#
# @lc app=leetcode.cn id=234 lang=python3
#
# [234] 回文链表
#
# https://leetcode.cn/problems/palindrome-linked-list/description/
#
# algorithms
# Easy (52.33%)
# Likes:    1483
# Dislikes: 0
# Total Accepted:    490.3K
# Total Submissions: 936.7K
# Testcase Example:  '[1,2,2,1]'
#
# 给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。
#
#
#
# 示例 1：
#
#
# 输入：head = [1,2,2,1]
# 输出：true
#
#
# 示例 2：
#
#
# 输入：head = [1,2]
# 输出：false
#
#
#
#
# 提示：
#
#
# 链表中节点数目在范围[1, 10^5] 内
# 0 <= Node.val <= 9
#
#
#
#
# 进阶：你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
#
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverse(self, head):
        if head == None or head.next == None:
            return head
        pre = None
        cur = head
        while cur:
            tmp = cur.next
            cur.next = pre
            pre = cur
            cur = tmp
        return pre

    def sf_ptr(self, head):
        if head == None:
            return head
        s = head
        f = head
        while f.next != None and f.next.next != None:
            f = f.next.next
            s = s.next
        return s

    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        if head == None:
            return True
        halfhead = self.sf_ptr(head)
        tailhead = self.reverse(halfhead.next)
        f = head
        s = tailhead
        res = True
        while res and s:
            if s.val != f.val:
                res = False
            s = s.next
            f = f.next
        halfhead.next = self.reverse(tailhead)
        return res
# @lc code=end
