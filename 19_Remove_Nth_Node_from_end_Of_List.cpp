// link to the problem ---> https://leetcode.com/problems/remove-nth-node-from-end-of-list/

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *prev = NULL;
        while (n--)
            fast = fast->next;
        while (fast != NULL)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        if (prev == NULL)
            head = head->next;
        else
            prev->next = slow->next;
        return head;
    }
};