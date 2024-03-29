#
# @lc app=leetcode.cn id=144 lang=python3
#
# [144] 二叉树的前序遍历
#
# https://leetcode.cn/problems/binary-tree-preorder-traversal/description/
#
# algorithms
# Easy (71.21%)
# Likes:    891
# Dislikes: 0
# Total Accepted:    682.8K
# Total Submissions: 958.4K
# Testcase Example:  '[1,null,2,3]'
#
# 给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
#
#
#
# 示例 1：
#
#
# 输入：root = [1,null,2,3]
# 输出：[1,2,3]
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
# 示例 4：
#
#
# 输入：root = [1,2]
# 输出：[1,2]
#
#
# 示例 5：
#
#
# 输入：root = [1,null,2]
# 输出：[1,2]
#
#
#
#
# 提示：
#
#
# 树中节点数目在范围 [0, 100] 内
# -100
#
#
#
#
# 进阶：递归算法很简单，你可以通过迭代算法完成吗？
#
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
# 递归
# class Solution:
#     def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
#         res = []
#         if root == None:
#             return []
#         def preorder(node):
#             if node == None:
#                 return
#             res.append(node.val)
#             preorder(node.left)
#             preorder(node.right)
#         preorder(root)
#         return res
class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        st = []
        res = []
        if root == None:
            return []
        st.append(root)
        while len(st) > 0:
            node = st[-1]
            st = st[:-1]
            res.append(node.val)
            if node.right:
                st.append(node.right)
            if node.left:
                st.append(node.left)
        return res
# @lc code=end
