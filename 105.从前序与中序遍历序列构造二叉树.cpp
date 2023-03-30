/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (71.38%)
 * Likes:    1764
 * Dislikes: 0
 * Total Accepted:    430K
 * Total Submissions: 602.5K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder
 * 是同一棵树的中序遍历，请构造二叉树并返回其根节点。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * 输出: [3,9,20,null,null,15,7]
 *
 *
 * 示例 2:
 *
 *
 * 输入: preorder = [-1], inorder = [-1]
 * 输出: [-1]
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= preorder.length <= 3000
 * inorder.length == preorder.length
 * -3000 <= preorder[i], inorder[i] <= 3000
 * preorder 和 inorder 均 无重复 元素
 * inorder 均出现在 preorder
 * preorder 保证 为二叉树的前序遍历序列
 * inorder 保证 为二叉树的中序遍历序列
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
// https://www.bilibili.com/video/BV1z34y1Y7T7/?spm_id_from=333.337.search-card.all.click&vd_source=b528fb16c8de754b7d88e0bc8622709c
class Solution
{
public:
    unordered_map<int, int> index;
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n = inorder.size();
        for (int i = 0; i < inorder.size(); i++)
        {
            index[inorder[i]] = i;
        }
        return dfs(preorder, inorder, 0, n - 1, 0, n - 1);
    }

private:
    TreeNode *dfs(const vector<int> &preorder, const vector<int> &inorder, int pre_left, int pre_right, int in_left, int in_right)
    {
        if (pre_left > pre_right)
        {
            return nullptr;
        }
        int root_val = preorder[pre_left];
        TreeNode *root = new TreeNode(root_val);

        int in_ptr = index[root_val];
        int len_left = in_ptr - in_left;
        // cout << root_val << "  " << in_ptr << "  " << len_left << endl;
        root->left = dfs(preorder, inorder, pre_left + 1, pre_left + len_left, in_left, in_ptr - 1);
        root->right = dfs(preorder, inorder, pre_left + len_left + 1, pre_right, in_ptr + 1, in_right);
        return root;
    }
};
// @lc code=end
