/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
   ListNode *reverseLL(ListNode *head,ListNode *prev){
       if(head==NULL){
           return prev;
       }
    
       ListNode *temp = head->next;
       head->next = prev;
       return reverseLL(temp,head);

   }


    int solve(ListNode *head){
          int counter=0;
          ListNode *temp3 = head;
          while(temp3!=NULL){
              temp3 = temp3->next;
              counter++;
          }
           return counter;

    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL){
            return NULL;
        }

         int total_length = solve(head);
         k = k%total_length;
         if(k==0){
             return head;
         }
         int rest = total_length - k;

         ListNode *prev = NULL;
         ListNode *temp = head;
         while(rest--){
             prev = temp;
             temp = temp->next;
         }
         if(prev!=NULL)
           prev ->next = NULL;

       
         ListNode *temp2 = temp;
         while(temp2->next!=NULL){
             temp2 = temp2->next;
         }
         temp2->next = head;
         return temp;
    }
};
