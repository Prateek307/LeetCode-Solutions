// link to the problem ---> https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            // List is empty or has only one node
            return nullptr;
        }

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = nullptr;

        // Move fast pointer two steps ahead and slow pointer one step ahead
        // When fast pointer reaches the end, slow pointer will be at the middle
        while (fast != nullptr && fast->next != nullptr)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Delete the middle node by adjusting pointers
        prev->next = slow->next;
        delete slow;

        return head;
    }
};