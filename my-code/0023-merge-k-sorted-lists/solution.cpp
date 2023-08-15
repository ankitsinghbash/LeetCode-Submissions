class Solution {
public:
   void solve(ListNode *&head, int data){
       if(head==NULL){
           ListNode *new_node = new ListNode(data);
           head = new_node;
           return;
       }
    
       //Insert first postion case:
      
       ListNode *temp1 = head;
       if(data<temp1->val){
           ListNode *new_node = new ListNode(data);
           new_node->next = temp1;
           head = new_node;
           return;
       }


       
       ListNode *temp = head;
       ListNode *prev = NULL;
       while(temp!=NULL){
              if(data<temp->val){
                  ListNode *new_node = new ListNode(data);
                  ListNode *delta = new_node;
                  prev->next = NULL;
                  prev->next = delta;
                  new_node->next = temp;
                  return;
              }
              prev = temp;
              temp=temp->next;
       }

       ListNode *new_node = new ListNode(data);
       prev->next = new_node;

   }




    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = NULL;
        for(int i=0;i<lists.size();i++){
            ListNode *head1 = lists[i];
            ListNode *temp = head1;
            while(temp!=NULL){
                solve(head,temp->val);
                temp = temp->next;
            }
        }
        return head;
    }
};
