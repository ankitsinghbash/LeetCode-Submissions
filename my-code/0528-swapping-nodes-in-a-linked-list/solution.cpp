class Solution {
public:
   
   int length(ListNode *head){
     int cnt = 0;
     while(head!=NULL){
          head=head->next;
          cnt++;
     }
      return cnt;
   }
    

    ListNode* swapNodes(ListNode* head, int k) {
        int total_len = length(head);
        ListNode *start = head;
        ListNode *tail = head;
        int cnt=1;
        while(cnt<k){
               start = start->next;
               cnt++;
        }

        cnt=1;
        int x = total_len-k+1;
        while(cnt<x){
            tail=tail->next;
            cnt++;
        }
        swap(start->val,tail->val);
        return head;

    }
};
