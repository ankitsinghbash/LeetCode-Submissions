class Solution {
public:
    bool solve(ListNode *&head){
         ListNode *fast = head;
         ListNode *slow = head;
         while(fast!=NULL && fast->next!=NULL){
               fast = fast->next->next;
               slow = slow->next;
               if(fast==slow){
                   return true;
               }
         }
         return false;
    }

    bool hasCycle(ListNode *head) {
        return solve(head);
    }
};
