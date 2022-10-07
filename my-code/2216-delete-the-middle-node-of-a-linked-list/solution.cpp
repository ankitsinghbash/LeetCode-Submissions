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
  
   ListNode *deleteElement(ListNode *&head)
   {
      if(head==NULL)
      {
          return head;
      }

      if(head->next==NULL)
      {
          head=NULL;
          return head;
      }      

       ListNode *slow=head;
       ListNode *fast=head;
       ListNode *prev=NULL;
       while(fast!=NULL&&fast->next!=NULL)  //condition change according to question but main is while(fast->next!=NULL&&fast->next->next1=NULL)
       {
           prev=slow;
           slow=slow->next;
           fast=fast->next->next;
       }
       prev->next=slow->next;
       return head;
   }


    ListNode* deleteMiddle(ListNode* head) {
        //fast slow pointer concept:
        ListNode *temp = deleteElement(head);
        return temp;
    }
};



