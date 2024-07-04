class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
       
       ListNode *temp = head;
       int sum=0;
       ListNode *dummy = new ListNode(-1);
       ListNode *list_node = dummy;
       while(temp!=NULL){
           if(temp->val==0 && sum != 0){
              //add the current sum as a node of liinked list:
              ListNode *new_node = new ListNode(sum);
              list_node->next = new_node;
              list_node = new_node;
              sum=0;
              
           }
           sum+=temp->val;
           temp = temp->next;
       }
  
       return dummy->next;




       
    }
};


// 0 1 2 0 0 0 3 1 2 0
//3 3


