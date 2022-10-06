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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)
        {
            return head;
        }
        ListNode *temp=head;
        ListNode *prev = NULL;
        ListNode *current=NULL;
         
        while(temp!=NULL)
        {
            current=temp->next;
            temp->next=prev;
            
            prev=temp;
            temp=current;
        }
       return prev;
    }
};

*/
//recursive approach:
class Solution {
public:
   
   ListNode *reverseLL(ListNode *current,ListNode *prev)
   {
    
     //base case:
     if(!current)
     {
         return prev;
     }
    
     ListNode *temp = current->next;
     current->next=prev;
     return reverseLL(temp,current);
   }

    ListNode* reverseList(ListNode* head) {
       return reverseLL(head,NULL);
       
    }
};

 
   
