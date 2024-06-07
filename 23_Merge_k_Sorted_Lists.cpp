// link to the problem ---> https://leetcode.com/problems/merge-k-sorted-lists/


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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *root = new ListNode(-1);
        priority_queue<pair<int, ListNode *>> pq;
        int n = lists.size();
        for (int i = 0; i < n; i++)
        {
            auto node = lists[i];
            if (node)
            {
                int val = node->val;
                pq.push({-1 * val, node});
            }
        }
        ListNode *temp = root;
        while (pq.size() > 0)
        {
            int val = -1 * pq.top().first;
            auto node = pq.top().second;
            temp->next = node;
            temp = temp->next;
            pq.pop();
            if (node->next)
            {
                pq.push({-1 * node->next->val, node->next});
            }
        }
        return root->next;
    }
};