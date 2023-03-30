/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 *
 * https://leetcode.cn/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Easy (71.21%)
 * Likes:    891
 * Dislikes: 0
 * Total Accepted:    682.8K
 * Total Submissions: 958.4K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [1,null,2,3]
 * 输出：[1,2,3]
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = []
 * 输出：[]
 *
 *
 * 示例 3：
 *
 *
 * 输入：root = [1]
 * 输出：[1]
 *
 *
 * 示例 4：
 *
 *
 * 输入：root = [1,2]
 * 输出：[1,2]
 *
 *
 * 示例 5：
 *
 *
 * 输入：root = [1,null,2]
 * 输出：[1,2]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目在范围 [0, 100] 内
 * -100
 *
 *
 *
 *
 * 进阶：递归算法很简单，你可以通过迭代算法完成吗？
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
// 递归
//  class Solution {
//  public:
//      vector<int> res;
//      vector<int> preorderTraversal(TreeNode* root) {
//          if (root == nullptr){
//              return res;
//          }
//          res.emplace_back(root->val);
//          preorderTraversal(root->left);
//          preorderTraversal(root->right);
//          return res;
//      }
//  };
// 迭代
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st;
        vector<int> res;
        if (root == nullptr)
        {
            return {};
        }
        st.emplace(root);
        while (!st.empty())
        {
            TreeNode *Node = st.top();
            st.pop();
            res.emplace_back(Node->val);
            if (Node->right != nullptr)
            {
                st.emplace(Node->right);
            }
            if (Node->left != nullptr)
            {
                st.emplace(Node->left);
            }
        }
        return res;
    }
};
// @lc code=end
