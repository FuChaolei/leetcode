#
# @lc app=leetcode.cn id=101 lang=python3
#
# [101] 对称二叉树
#
# https://leetcode.cn/problems/symmetric-tree/description/
#
# algorithms
# Easy (58.19%)
# Likes:    2076
# Dislikes: 0
# Total Accepted:    671.1K
# Total Submissions: 1.2M
# Testcase Example:  '[1,2,2,3,4,4,3]'
#
# 给你一个二叉树的根节点 root ， 检查它是否轴对称。
#
#
#
# 示例 1：
#
#
# 输入：root = [1,2,2,3,4,4,3]
# 输出：true
#
#
# 示例 2：
#
#
# 输入：root = [1,2,2,null,3,null,3]
# 输出：false
#
#
#
#
# 提示：
#
#
# 树中节点数目在范围 [1, 1000] 内
# -100 <= Node.val <= 100
#
#
#
#
# 进阶：你可以运用递归和迭代两种方法解决这个问题吗？
#
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
import queue


class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        if root == None:
            return True
        qu = queue.Queue()
        qu.put((root, root))
        while not qu.empty():
            front = qu.get()
            tmp1 = front[0]
            tmp2 = front[1]
            if tmp1 == tmp2 == None:
                continue
            if tmp1 == None or tmp2 == None or tmp1.val != tmp2.val:
                return False
            qu.put((tmp1.left, tmp2.right))
            qu.put((tmp1.right, tmp2.left))
        return True
# class Solution:
#     def check(self, left, right):
#         if left == None and right == None:
#             return True
#         if left == None or right == None or left.val != right.val:
#             return False
#         return self.check(left.left, right.right) and self.check(left.right, right.left)

#     def isSymmetric(self, root: Optional[TreeNode]) -> bool:
#         return self.check(root, root)
# @lc code=end
