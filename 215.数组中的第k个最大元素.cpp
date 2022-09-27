/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 *
 * https://leetcode.cn/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (64.50%)
 * Likes:    1888
 * Dislikes: 0
 * Total Accepted:    747K
 * Total Submissions: 1.2M
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
 *
 * 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 *
 * 你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: [3,2,1,5,6,4], k = 2
 * 输出: 5
 *
 *
 * 示例 2:
 *
 *
 * 输入: [3,2,3,1,2,4,5,5,6], k = 4
 * 输出: 4
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= k <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int n = nums.size();
        srand(time(NULL));
        return qsort(nums, 0, n - 1, k);
    }
    int qsort(vector<int> &nums, int l, int r, int &k)
    {
        for (auto i : nums)
        {
            cout << i << " ";
        }
        cout << endl;
        int m = rand() % (r - l + 1) + l;
        swap(nums[l], nums[m]);
        int t = nums[l];
        int x = l, y = r;
        for (auto i : nums)
        {
            cout << i << " ";
        }
        cout << endl;
        cout << "l:" << l << " r:" << r << " m:" << m << endl;
        while (x < y)
        {
            while (nums[x] >= t && x < y)
            {
                cout << nums[x] << endl;
                x++;
            }
            while (nums[y] <= t && x < y)
            {
                y--;
            }
            swap(nums[x], nums[y]);
            for (auto i : nums)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        swap(nums[l], nums[x]);
        for (auto i : nums)
        {
            cout << i << " ";
        }
        cout << endl;
        cout << "x:" << x << endl;
        if (x == k - 1)
        {
            return nums[x];
        }
        else if (x < k - 1)
        {
            return qsort(nums, x + 1, r, k);
        }
        else
        {
            return qsort(nums, l, x - 1, k);
        }
    }
};
// @lc code=end
