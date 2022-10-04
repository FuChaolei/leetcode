/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode.cn/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (37.17%)
 * Likes:    5773
 * Dislikes: 0
 * Total Accepted:    1.2M
 * Total Submissions: 3.3M
 * Testcase Example:  '"babad"'
 *
 * 给你一个字符串 s，找到 s 中最长的回文子串。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "babad"
 * 输出："bab"
 * 解释："aba" 同样是符合题意的答案。
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "cbbd"
 * 输出："bb"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 1000
 * s 仅由数字和英文字母组成
 *
 *
 */

// @lc code=start
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        auto getlenth = [=](int l, int r)
        {
            while (l >= 0 && r < n && s[l] == s[r])
            {
                l--;
                r++;
            }
            return r - l - 1;
        };
        int cur = 0;
        int start = 0;
        int len = 0;
        for (int i = 0; i < n; i++)
        {
            cur = max(getlenth(i, i), getlenth(i, i + 1));
            if (cur > len)
            {
                len = cur;
                start = i - (len - 1) / 2;
            }
        }
        return s.substr(start, len);
    }
};
// @lc code=end
