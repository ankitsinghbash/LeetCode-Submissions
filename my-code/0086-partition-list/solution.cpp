class Solution {
public:
   void firstLL(ListNode *&head1,int x){
       
             ListNode *new_node = new ListNode(x);
             if(head1==NULL){
                  head1 = new_node;
             }
             else{
                  ListNode *temp = head1;
                  while(temp->next!=NULL){
                     temp = temp->next;
                  }
                  temp->next = new_node;
             }

   }


   void secondLL(ListNode *&head2,int x){
       
             ListNode *new_node = new ListNode(x);
             if(head2==NULL){
                  head2 = new_node;
             }
             else{
                  ListNode *temp = head2;
                  while(temp->next!=NULL){
                     temp = temp->next;
                  }
                  temp->next = new_node;
             }

   }
   ListNode *merge_LL(ListNode *head1,ListNode *head2){
     
        if(head1==NULL){
            return head2;
        }


         ListNode *temp = head1;
         while(temp->next!=NULL){
            temp=temp->next;
         }

        temp->next=head2;
       return head1;
      
   }
  
    ListNode* partition(ListNode* head, int x) {
           
           ListNode *temp = head;
           ListNode *head1 = NULL;
           ListNode *head2 = NULL;
           while(temp!=NULL){
                if(temp->val<x){
                      firstLL(head1,temp->val);
                }
                else{
                       secondLL(head2,temp->val);
                }
                temp = temp->next;
           }

           ListNode *myans = merge_LL(head1,head2);
           return myans;

    }
};
