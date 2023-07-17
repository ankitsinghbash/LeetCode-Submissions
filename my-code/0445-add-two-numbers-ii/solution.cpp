class Solution {
public:
  ListNode *Reverse(ListNode *head,ListNode *prev){
     if(head==NULL) return prev;
     ListNode *temp = head->next;
     head->next = prev;
     return Reverse(temp,head);
  }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head1 = Reverse(l1,NULL);
        ListNode *head2 = Reverse(l2,NULL);
        ListNode *dummy = NULL;
        int carry = 0;
        while(head1!=NULL || head2!=NULL || carry!=0){
          int x = carry;
          if(head1!=NULL){
              x+=head1->val;
          }
          if(head2!=NULL){
              x+=head2->val;
          }

          ListNode *nn = new ListNode(x%10);
          nn->next = dummy;
          dummy = nn;
   
         carry = x/10;
         if(head1!=NULL){
             head1=head1->next;
         }
         if(head2!=NULL){
             head2=head2->next;
         }
        }

       
        return dummy;
    }
};
