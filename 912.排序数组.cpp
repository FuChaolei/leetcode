/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 *
 * https://leetcode.cn/problems/sort-an-array/description/
 *
 * algorithms
 * Medium (55.16%)
 * Likes:    697
 * Dislikes: 0
 * Total Accepted:    456.7K
 * Total Submissions: 828.6K
 * Testcase Example:  '[5,2,3,1]'
 *
 * 给你一个整数数组 nums，请你将该数组升序排列。
 *
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [5,2,3,1]
 * 输出：[1,2,3,5]
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [5,1,1,2,0,0]
 * 输出：[0,0,1,1,2,5]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 5 * 10^4
 * -5 * 10^4 <= nums[i] <= 5 * 10^4
 *
 *
 */

// @lc code=start
// https://blog.csdn.net/Xiao_brother/article/details/120753125
class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        srand(time(NULL));
        int n = nums.size();
        qsort(nums, 0, n - 1);
        return nums;
    }
    void qsort(vector<int> &nums, int l, int r)
    {
        if (l >= r)
        {
            return;
        }
        int m = rand() % (r - l + 1) + l;
        swap(nums[l], nums[m]);
        int t = nums[l];
        int x = l, y = r;
        while (x < y)
        {
            while (x < y && nums[y] >= t)
            {
                y--;
            }
            while (x < y && nums[x] <= t)
            {
                x++;
            }
            swap(nums[x], nums[y]);
        }
        swap(nums[x], nums[l]);
        qsort(nums, l, x - 1);
        qsort(nums, x + 1, r);
    }
};
// @lc code=end
