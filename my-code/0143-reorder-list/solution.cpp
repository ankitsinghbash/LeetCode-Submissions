class Solution {
public:
    ListNode *reverse_LL(ListNode *head,ListNode *prev){
        if(head==NULL) return prev;

        ListNode *temp = head->next;
        head->next = prev;
        return reverse_LL(temp,head);

    }

    void reorderList(ListNode* &head) {
    
        ListNode *temp1 = head;

        ListNode *slow = head;
        ListNode *fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode *dummy = reverse_LL(slow,NULL);
        
      ListNode *curr = head;
      ListNode *LLhalf = dummy;
  
      ListNode *curr_next=NULL;
      ListNode *temp = NULL;
      while(curr->next!=NULL && LLhalf->next!=NULL){    //both condition is required because they are two diff Linkedlist and it helf in when an odd number of node in original LinkList:
          curr_next = curr->next;
          curr->next = LLhalf;
          temp = LLhalf->next;
          LLhalf->next = curr_next;
          LLhalf=temp;
          curr = curr_next;
      }
    }
};
