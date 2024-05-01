// link to the problem ---> https://leetcode.com/problems/reverse-nodes-in-k-group/description/?envType=study-plan-v2&envId=top-interview-150

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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == NULL)
            return NULL;

        // step1:  reverse first K nodes
        ListNode *next = NULL;
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *check = head;
        // step1: There are fewer than k nodes remaining
        for (int i = 0; i < k; i++)
        {
            if (check == NULL)
                return head;
            check = check->next;
        }
        // step3: Recursion
        int count = 0;
        while (curr != NULL && count < k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        // step4: Return head of reversed linked list
        if (next != NULL)
        {
            head->next = reverseKGroup(next, k);
        }
        return prev;
    }
};