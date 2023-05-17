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

   
     ListNode* reverseList(ListNode* head) {
       ListNode *curr = head;
       ListNode *temp = NULL;
       ListNode *prev = NULL;
       while(curr!=NULL){
           temp = curr->next;
           curr->next=prev;
           prev=curr;
           curr = temp;
       }
       return prev;
    }

    void reorderList(ListNode* head) {

 //        if(!head->next) return;


      ListNode *slow = head;
      ListNode *fast = head;
      while(fast!=NULL && fast->next!=NULL){
          slow=slow->next;
          fast=fast->next->next;
      }

      ListNode *dummy = reverseList(slow);  //dummy not only give the head: //it's given a new linkedlist with dummy as a head:

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
