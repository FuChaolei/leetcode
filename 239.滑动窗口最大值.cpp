/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 *
 * https://leetcode.cn/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (49.97%)
 * Likes:    1989
 * Dislikes: 0
 * Total Accepted:    378.7K
 * Total Submissions: 758.2K
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k
 * 个数字。滑动窗口每次只向右移动一位。
 *
 * 返回 滑动窗口中的最大值 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
 * 输出：[3,3,5,5,6,7]
 * 解释：
 * 滑动窗口的位置                最大值
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1], k = 1
 * 输出：[1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 1 <= k <= nums.length
 *
 *
 */

// @lc code=start
// class Solution
// {
// public:
//     vector<int> maxSlidingWindow(vector<int> &nums, int k)
//     {
//         priority_queue<pair<int, int>> q;
//         for (int i = 0; i < k; i++)
//         {
//             q.emplace(nums[i], i);
//         }
//         vector<int> res{q.top().first};
//         for (int i = k; i < nums.size(); i++)
//         {
//             q.emplace(nums[i], i);
//             while (q.top().second <= i - k)
//             {
//                 q.pop();
//             }
//             res.emplace_back(q.top().first);
//         }
//         return res;
//     }
// };
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> q;
        vector<int> res;
        for (int i = 0; i < k; i++)
        {
            while (!q.empty() && nums[q.back()] <= nums[i])
            {
                q.pop_back();
            }
            q.emplace_back(i);
        }
        res.emplace_back(nums[q.front()]);
        for (int i = k; i < nums.size(); i++)
        {
            while (!q.empty() && q.front() <= i - k)
            {
                q.pop_front();
            }
            while (!q.empty() && nums[q.back()] <= nums[i])
            {
                q.pop_back();
            }
            q.emplace_back(i);
            res.emplace_back(nums[q.front()]);
        }
        return res;
    }
};
// @lc code=end
