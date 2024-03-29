/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 *
 * https://leetcode.cn/problems/edit-distance/description/
 *
 * algorithms
 * Hard (62.74%)
 * Likes:    2675
 * Dislikes: 0
 * Total Accepted:    318.6K
 * Total Submissions: 507.9K
 * Testcase Example:  '"horse"\n"ros"'
 *
 * 给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。
 *
 * 你可以对一个单词进行如下三种操作：
 *
 *
 * 插入一个字符
 * 删除一个字符
 * 替换一个字符
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：word1 = "horse", word2 = "ros"
 * 输出：3
 * 解释：
 * horse -> rorse (将 'h' 替换为 'r')
 * rorse -> rose (删除 'r')
 * rose -> ros (删除 'e')
 *
 *
 * 示例 2：
 *
 *
 * 输入：word1 = "intention", word2 = "execution"
 * 输出：5
 * 解释：
 * intention -> inention (删除 't')
 * inention -> enention (将 'i' 替换为 'e')
 * enention -> exention (将 'n' 替换为 'x')
 * exention -> exection (将 'n' 替换为 'c')
 * exection -> execution (插入 'u')
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= word1.length, word2.length <= 500
 * word1 和 word2 由小写英文字母组成
 *
 *
 */
//!!!花花酱
// @lc code=start
//递归
// class Solution
// {
// public:
//     int minDistance(string word1, string word2)
//     {
//         int l1 = word1.size();
//         int l2 = word2.size();
//         dp = vector<vector<int>>(l1 + 1, vector<int>(l2 + 1, -1));
//         return minDistance(word1, word2, l1, l2);
//     }

// private:
//     vector<vector<int>> dp;
//     int minDistance(string &word1, string &word2, int l1, int l2)
//     {
//         if (l1 == 0)
//         {
//             return l2;
//         }
//         if (l2 == 0)
//         {
//             return l1;
//         }
//         if (dp[l1][l2] >= 0)
//         {
//             return dp[l1][l2];
//         }
//         int ans;
//         if (word1[l1 - 1] == word2[l2 - 1])
//         {
//             ans = minDistance(word1, word2, l1 - 1, l2 - 1);
//         }
//         else
//         {
//             ans = 1 + min(minDistance(word1, word2, l1 - 1, l2 - 1), min(minDistance(word1, word2, l1 - 1, l2), minDistance(word1, word2, l1, l2 - 1)));
//         }
//         return dp[l1][l2] = ans;
//     }
// };
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int l1 = word1.size();
        int l2 = word2.size();
        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, -1));
        for (int i = 0; i <= l1; i++)
        {
            dp[i][0] = i;
        }
        for (int i = 0; i <= l2; i++)
        {
            dp[0][i] = i;
        }
        for (int i = 1; i <= l1; i++)
        {
            for (int j = 1; j <= l2; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                }
            }
        }
        // for (int i = 0; i <= l1; i++)
        // {
        //     for (int j = 0; j <= l2; j++)
        //     {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return dp[l1][l2];
    }
};
// @lc code=end
