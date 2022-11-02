#
# @lc app=leetcode.cn id=23 lang=python3
#
# [23] 合并K个升序链表
#
# https://leetcode.cn/problems/merge-k-sorted-lists/description/
#
# algorithms
# Hard (57.31%)
# Likes:    2233
# Dislikes: 0
# Total Accepted:    566.3K
# Total Submissions: 987.2K
# Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
#
# 给你一个链表数组，每个链表都已经按升序排列。
#
# 请你将所有链表合并到一个升序链表中，返回合并后的链表。
#
#
#
# 示例 1：
#
# 输入：lists = [[1,4,5],[1,3,4],[2,6]]
# 输出：[1,1,2,3,4,4,5,6]
# 解释：链表数组如下：
# [
# ⁠ 1->4->5,
# ⁠ 1->3->4,
# ⁠ 2->6
# ]
# 将它们合并到一个有序链表中得到。
# 1->1->2->3->4->4->5->6
#
#
# 示例 2：
#
# 输入：lists = []
# 输出：[]
#
#
# 示例 3：
#
# 输入：lists = [[]]
# 输出：[]
#
#
#
#
# 提示：
#
#
# k == lists.length
# 0 <= k <= 10^4
# 0 <= lists[i].length <= 500
# -10^4 <= lists[i][j] <= 10^4
# lists[i] 按 升序 排列
# lists[i].length 的总和不超过 10^4
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
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        def mergeTwo(l1,l2):
            dummy = ListNode(0)
            cur =dummy
            while l1 and l2:
                if l2.val<l1.val:
                    l1,l2 = l2,l1
                cur.next = l1
                l1 = l1.next
                cur = cur.next
            if l1:
                cur.next = l1
            if l2:
                cur.next = l2
            return dummy.next
        def merge(lists,l,r):
            if l>r:
                return None
            if l==r:
                return lists[l]
            if l+1==r:
                return mergeTwo(lists[l],lists[r])
            mid = l+(r-l)//2
            left = merge(lists,l,mid)
            right = merge(lists,mid+1,r)
            return mergeTwo(left,right)
        return merge(lists,0,len(lists)-1)
# @lc code=end

