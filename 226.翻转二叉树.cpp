/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
 *
 * https://leetcode.cn/problems/invert-binary-tree/description/
 *
 * algorithms
 * Easy (79.34%)
 * Likes:    1388
 * Dislikes: 0
 * Total Accepted:    526K
 * Total Submissions: 662.9K
 * Testcase Example:  '[4,2,7,1,3,6,9]'
 *
 * 给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：root = [4,2,7,1,3,6,9]
 * 输出：[4,7,2,9,6,3,1]
 *
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入：root = [2,1,3]
 * 输出：[2,3,1]
 *
 *
 * 示例 3：
 *
 *
 * 输入：root = []
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目范围在 [0, 100] 内
 * -100 <= Node.val <= 100
 *
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
            return root;
        TreeNode *left = invertTree(root->left);
        TreeNode *right = invertTree(root->right);
        root->right = left;
        root->left = right;
        return root;
    }
};
// @lc code=end
