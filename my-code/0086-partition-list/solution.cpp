class Solution {
public:
void firsthead(ListNode *&head1,int data){
      
      if(head1==NULL){
          ListNode *new_node = new ListNode(data);
          head1 = new_node;
          return;
      }

      ListNode *temp = head1;
      while(temp->next!=NULL){
          temp = temp->next;
      }
      ListNode *new_node = new ListNode(data);
      temp->next = new_node;
}


void secondhead(ListNode *&head2,int data){
      
      if(head2==NULL){
          ListNode *new_node = new ListNode(data);
          head2 = new_node;
          return;
      }

      ListNode *temp = head2;
      while(temp->next!=NULL){
          temp = temp->next;
      }
      ListNode *new_node = new ListNode(data);
      temp->next = new_node;
}

ListNode *solve(ListNode *&head1,ListNode *&head2){
    if(head1==NULL && head2==NULL){
        return NULL;
    }

    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }

    ListNode *temp = head1;
    while(temp->next!=NULL){
         temp=temp->next;
    }
    temp->next=head2;
    return head1;
}


    ListNode* partition(ListNode* head, int x) {
        ListNode *head1=NULL;
        ListNode *head2=NULL;
  
        ListNode *temp = head;
        while(temp!=NULL){
            if(temp->val<x){
                firsthead(head1,temp->val);
            }
            else if(temp->val>=x){
                secondhead(head2,temp->val);
            }
            temp=temp->next;
        }
      

       //add both first and second head:
       ListNode *answer = solve(head1,head2);
       return answer;

    }
};
