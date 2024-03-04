class Solution {
public:
    int total_node(ListNode *&head){
           int cnt=0;
           ListNode *temp = head;
           while(temp!=NULL){
               temp = temp->next;
               cnt++;
           }
           return cnt;
    }


    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int total = total_node(head);
        int node_num = total-n+1;
        if(node_num==1){
            return head->next;
        }

        ListNode *temp = head;
        ListNode *prev = NULL;
        ListNode *new_node = NULL;
        int cnt=0;
        while(cnt<=node_num-2){
            prev = temp;
            temp = temp->next;
            new_node = temp->next;
            cnt++;
        }
     
        if(cnt==0) return prev;
        prev->next = new_node;
        return head;
         
    }
};
