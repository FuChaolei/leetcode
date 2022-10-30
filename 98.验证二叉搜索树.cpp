/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 *
 * https://leetcode.cn/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (36.60%)
 * Likes:    1795
 * Dislikes: 0
 * Total Accepted:    620.6K
 * Total Submissions: 1.7M
 * Testcase Example:  '[2,1,3]'
 *
 * 给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
 *
 * 有效 二叉搜索树定义如下：
 *
 *
 * 节点的左子树只包含 小于 当前节点的数。
 * 节点的右子树只包含 大于 当前节点的数。
 * 所有左子树和右子树自身必须也是二叉搜索树。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [2,1,3]
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [5,1,4,null,null,3,6]
 * 输出：false
 * 解释：根节点的值是 5 ，但是右子节点的值是 4 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目范围在[1, 10^4] 内
 * -2^31 <= Node.val <= 2^31 - 1
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
// class Solution
// {
// public:
//     vector<int> res;
//     bool isValidBST(TreeNode *root)
//     {
//         inorder(root);
//         if (res.size() <= 1)
//         {
//             return true;
//         }
//         for (int i = 1; i < res.size(); i++)
//         {
//             if (res[i] == res[i - 1])
//                 return false;
//         }
//         vector<int> nums = res;
//         sort(nums.begin(), nums.end());
//         return nums == res;
//     }

// private:
//     void inorder(TreeNode *root)
//     {
//         if (root == nullptr)
//         {
//             return;
//         }
//         inorder(root->left);
//         res.emplace_back(root->val);
//         inorder(root->right);
//     }
// };
class Solution
{
public:
    // long long pre = LLONG_MIN;
    TreeNode *pre = nullptr;
    bool isValidBST(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        bool left = isValidBST(root->left);
        if (pre == nullptr)
        {
            pre = root;
        }
        else if (root->val <= pre->val)
        {
            return false;
        }
        pre = root;
        bool right = isValidBST(root->right);
        return left && right;
    }
};
// @lc code=end
