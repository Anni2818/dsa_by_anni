// approach is 
// keep 3 pointers = temp for iteration,prev and front aswell
// while you traverse keep next node in front so that you dont lose the ll,reverse the pointer and then move prev and temp forward

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp=head;
        ListNode* prev=NULL;
        ListNode* front = NULL;
        while(temp)
        {
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
};