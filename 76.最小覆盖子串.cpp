/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 *
 * https://leetcode.cn/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (44.98%)
 * Likes:    2262
 * Dislikes: 0
 * Total Accepted:    371K
 * Total Submissions: 824.8K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 ""
 * 。
 *
 *
 *
 * 注意：
 *
 *
 * 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
 * 如果 s 中存在这样的子串，我们保证它是唯一的答案。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "ADOBECODEBANC", t = "ABC"
 * 输出："BANC"
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "a", t = "a"
 * 输出："a"
 *
 *
 * 示例 3:
 *
 *
 * 输入: s = "a", t = "aa"
 * 输出: ""
 * 解释: t 中两个字符 'a' 均应包含在 s 的子串中，
 * 因此没有符合条件的子字符串，返回空字符串。
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * s 和 t 由英文字母组成
 *
 *
 *
 * 进阶：你能设计一个在 o(n) 时间内解决此问题的算法吗？
 */

// @lc code=start
// https://leetcode.cn/problems/minimum-window-substring/solution/leetcode-76-zui-xiao-fu-gai-zi-chuan-cja-lmqz/
class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> hs, ht;
        for (auto a : t)
        {
            ht[a]++;
        }
        int cnt = 0;
        string res;
        for (int i = 0, j = 0; i < s.size(); i++)
        {
            hs[s[i]]++;
            if (hs[s[i]] <= ht[s[i]])
            {
                cnt++;
            }
            while (hs[s[j]] > ht[s[j]])
            {
                hs[s[j++]]--;
            }
            if (cnt == t.size())
            {
                if (res.empty() || res.size() > i - j + 1)
                {
                    res = s.substr(j, i - j + 1);
                }
            }
        }
        return res;
    }
};

// @lc code=end
