#
# @lc app=leetcode.cn id=148 lang=python3
#
# [148] 排序链表
#
# https://leetcode.cn/problems/sort-list/description/
#
# algorithms
# Medium (66.18%)
# Likes:    1804
# Dislikes: 0
# Total Accepted:    352.7K
# Total Submissions: 533.1K
# Testcase Example:  '[4,2,1,3]'
#
# 给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
#
#
#
#
#
#
# 示例 1：
#
#
# 输入：head = [4,2,1,3]
# 输出：[1,2,3,4]
#
#
# 示例 2：
#
#
# 输入：head = [-1,5,3,4,0]
# 输出：[-1,0,3,4,5]
#
#
# 示例 3：
#
#
# 输入：head = []
# 输出：[]
#
#
#
#
# 提示：
#
#
# 链表中节点的数目在范围 [0, 5 * 10^4] 内
# -10^5 <= Node.val <= 10^5
#
#
#
#
# 进阶：你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？
#
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        def merge(l1, l2):
            dummy = ListNode(0)
            cur = dummy
            while l1 != None and l2 != None:
                if l1.val > l2.val:
                    l1, l2 = l2, l1
                cur.next = l1
                l1 = l1.next
                cur = cur.next
            if l1 != None:
                cur.next = l1
            if l2 != None:
                cur.next = l2
            return dummy.next
        if head == None or head.next == None:
            return head
        s = head
        f = head.next
        while f != None and f.next != None:
            f = f.next.next
            s = s.next
        mid = s.next
        s.next = None
        return merge(self.sortList(head), self.sortList(mid))
# @lc code=end
