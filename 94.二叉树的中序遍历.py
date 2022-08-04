#
# @lc app=leetcode.cn id=94 lang=python3
#
# [94] 二叉树的中序遍历
#
# https://leetcode.cn/problems/binary-tree-inorder-traversal/description/
#
# algorithms
# Easy (75.99%)
# Likes:    1516
# Dislikes: 0
# Total Accepted:    902.3K
# Total Submissions: 1.2M
# Testcase Example:  '[1,null,2,3]'
#
# 给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。
#
#
#
# 示例 1：
#
#
# 输入：root = [1,null,2,3]
# 输出：[1,3,2]
#
#
# 示例 2：
#
#
# 输入：root = []
# 输出：[]
#
#
# 示例 3：
#
#
# 输入：root = [1]
# 输出：[1]
#
#
#
#
# 提示：
#
#
# 树中节点数目在范围 [0, 100] 内
# -100 <= Node.val <= 100
#
#
#
#
# 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
#
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
# class Solution:
#     res = []
#     def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
#         res = []
#         def inorder(root):
#             if root ==None:
#                 return res
#             cur = root
#             inorder(cur.left)
#             res.append(cur.val)
#             inorder(cur.right)
#         inorder(root)
#         return res
# 迭代
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        st = []
        res = []
        cur = root
        while cur != None or len(st) > 0:
            if cur != None:
                st.append(cur)
                cur = cur.left
            else:
                cur = st[-1]
                res.append(cur.val)
                st = st[:-1]
                cur = cur.right
        return res
# @lc code=end
