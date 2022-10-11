/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 *
 * https://leetcode.cn/problems/reorder-list/description/
 *
 * algorithms
 * Medium (64.37%)
 * Likes:    1055
 * Dislikes: 0
 * Total Accepted:    215.3K
 * Total Submissions: 334.4K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个单链表 L 的头节点 head ，单链表 L 表示为：
 *
 *
 * L0 → L1 → … → Ln - 1 → Ln
 *
 *
 * 请将其重新排列后变为：
 *
 *
 * L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
 *
 * 不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：head = [1,2,3,4]
 * 输出：[1,4,2,3]
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入：head = [1,2,3,4,5]
 * 输出：[1,5,2,4,3]
 *
 *
 *
 * 提示：
 *
 *
 * 链表的长度范围为 [1, 5 * 10^4]
 * 1 <= node.val <= 1000
 *
 *
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    void reorderList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return;
        }
        ListNode *half = halfptr(head);
        ListNode *l1 = head;
        ListNode *l2 = half->next;
        half->next = nullptr;
        l2 = reverse(l2);
        merge(l1, l2);
    }

private:
    ListNode *halfptr(ListNode *head)
    {
        ListNode *s = head;
        ListNode *f = head;
        while (f != nullptr && f->next != nullptr)
        {
            f = f->next->next;
            s = s->next;
        }
        return s;
    }
    ListNode *reverse(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *p = nullptr;
        ListNode *cur = head;
        while (cur != nullptr)
        {
            ListNode *next = cur->next;
            cur->next = p;
            p = cur;
            cur = next;
        }
        return p;
    }
    void merge(ListNode *l1, ListNode *l2)
    {
        ListNode *l1next;
        ListNode *l2next;
        while (l1 != nullptr && l2 != nullptr)
        {
            l1next = l1->next;
            l2next = l2->next;
            l1->next = l2;
            l1 = l1next;
            l2->next = l1;
            l2 = l2next;
        }
    }
};
// @lc code=end
