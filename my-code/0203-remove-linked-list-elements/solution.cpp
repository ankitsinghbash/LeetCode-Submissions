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
 /*
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
     ListNode dummy(-1);
     dummy.next=head;
     ListNode *prev=&dummy;
     ListNode *curr = head;
     while(curr!=NULL)
     {
         if(curr->val==val)
         {
            curr=curr->next;
            prev->next=curr;
         }
         else{
             prev=prev->next;
             curr=curr->next;
         }
     }
      return dummy.next;

    }
};

*/


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
    if(head==NULL)
    {
        return head;
    }
     head->next = removeElements(head->next,val);
      return  (head->val == val) ?  head->next :  head;
      		
    }
};
