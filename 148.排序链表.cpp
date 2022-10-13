/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 *
 * https://leetcode.cn/problems/sort-list/description/
 *
 * algorithms
 * Medium (66.18%)
 * Likes:    1804
 * Dislikes: 0
 * Total Accepted:    352.7K
 * Total Submissions: 533.1K
 * Testcase Example:  '[4,2,1,3]'
 *
 * 给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
 *
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：head = [4,2,1,3]
 * 输出：[1,2,3,4]
 *
 *
 * 示例 2：
 *
 *
 * 输入：head = [-1,5,3,4,0]
 * 输出：[-1,0,3,4,5]
 *
 *
 * 示例 3：
 *
 *
 * 输入：head = []
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点的数目在范围 [0, 5 * 10^4] 内
 * -10^5 <= Node.val <= 10^5
 *
 *
 *
 *
 * 进阶：你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？
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
//空间log(n),时间nlog(n)
// class Solution
// {
// public:
//     ListNode *sortList(ListNode *head)
//     {
//         if (!head || !head->next)
//         {
//             return head;
//         }
//         ListNode *s = head, *f = head->next;
//         while (f != nullptr && f->next != nullptr)
//         {
//             s = s->next;
//             f = f->next->next;
//         }
//         ListNode *mid = s->next;
//         s->next = nullptr;
//         return merge(sortList(head), sortList(mid));
//         // return merge(head, mid);
//     }
//     ListNode *merge(ListNode *l1, ListNode *l2)
//     {
//         ListNode dummy(0);
//         ListNode *cur = &dummy;
//         while (l1 && l2)
//         {
//             if (l1->val > l2->val)
//             {
//                 swap(l1, l2);
//             }
//             cur->next = l1;
//             l1 = l1->next;
//             cur = cur->next;
//         }
//         if (l1)
//         {
//             cur->next = l1;
//         }
//         if (l2)
//         {
//             cur->next = l2;
//         }
//         return dummy.next;
//     }
// };
//空间O(1),时间nlog(n)
class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *l = head;
        ListNode *f = head->next;
        while (f && f->next)
        {
            f = f->next->next;
            s = s->next;
        }
    }
    ListNode *splist(ListNode *head, int n)
    {
        while (--n && head)
        {
            head = head->next;
        }
        ListNode *newhead = head ? head->next : nullptr;
        if (head)
        {
            head->next = nullptr;
        }
        return newhead;
    }
    pair<ListNode *, ListNode *> merge(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(0);
        ListNode *tail = &dummy;
        while (l1 && l2)
        {
            if (l1->val > l2->val)
            {
                swap(l1, l2);
            }
            tail->next = l1;
            l1 = l1->next;
            tail = tail->next;
        }
        if (l1)
        {
            tail->next = l1;
        }
        if (l2)
        {
            tail->next = l2;
        }
        while (tail->next)
        {
            tail = tail->next;
        }
        return {dummy.next, tail};
    }
};
// @lc code=end
