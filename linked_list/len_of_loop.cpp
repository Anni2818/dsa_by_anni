/*this is known as tortoise haire method to find len of loop
  just detect the loop and then increment one fo the pointer for counter*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        int count =0;
        Node*slow = head;
        Node*fast=head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                count++;
                fast = fast->next;
                while(slow!= fast){
                    count++;
                    fast = fast->next;
                }
                return count;
            }
        }
        return 0;
    }
};