/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 *
 * https://leetcode.cn/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (63.22%)
 * Likes:    856
 * Dislikes: 0
 * Total Accepted:    304.8K
 * Total Submissions: 482.2K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * 给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。
 *
 * 叶子节点 是指没有子节点的节点。
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
 * 输出：[[5,4,11,2],[5,8,4,5]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [1,2,3], targetSum = 5
 * 输出：[]
 *
 *
 * 示例 3：
 *
 *
 * 输入：root = [1,2], targetSum = 0
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点总数在范围 [0, 5000] 内
 * -1000
 * -1000
 *
 *
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
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
        {
            return res;
        }
        path.emplace_back(root->val);
        backtrace(root, targetSum - root->val);
        return res;
    }

private:
    void backtrace(TreeNode *root, int tar)
    {
        if (root == nullptr)
        {
            return;
        }
        if (tar == 0 && !root->left && !root->right)
        {
            res.emplace_back(path);
            return;
        }
        if (!root->left && !root->right)
        {
            return;
        }
        if (root->left)
        {
            path.emplace_back(root->left->val);
            tar -= root->left->val;
            backtrace(root->left, tar);
            tar += root->left->val;
            path.pop_back();
        }
        if (root->right)
        {
            path.emplace_back(root->right->val);
            tar -= root->right->val;
            backtrace(root->right, tar);
            tar += root->right->val;
            path.pop_back();
        }
        return;
    }
};
// @lc code=end
