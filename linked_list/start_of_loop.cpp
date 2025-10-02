//this is the code for detecting the start of loop in a linked list.
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast)
            {
                ListNode *temp = head;
                while (temp != fast)
                {
                    temp = temp->next;
                    fast = fast->next;
                }
                return temp;
            }
        }
        return NULL;
    }
};