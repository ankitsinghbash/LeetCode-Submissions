class Solution {
public:

    ListNode *reverse(ListNode *head,ListNode *prev){
             
            //iterative:

             if(head==NULL) return prev;

             ListNode *temp = head->next;
             head->next=prev;
             return reverse(temp,head);


    }

    ListNode* removeNodes(ListNode* head) {

          ListNode *head1 = reverse(head,NULL);
          
          
         
         //traversal in head1 means in the reverse of LList:
          ListNode *prev = head1;
          ListNode *temp = head1->next;
          int curr_maxx = head1->val;
          while(temp!=NULL){
                int curr = temp->val;
                if(curr<curr_maxx){
                        temp = temp->next;
                }
                else{
                     prev->next = temp;
                     prev = temp;
                     temp = temp->next;
                    
                }
                curr_maxx = max(curr_maxx,curr);
          }
          
           prev->next=NULL;
          ListNode *headans = reverse(head1,NULL);
          return headans;
    }
};
