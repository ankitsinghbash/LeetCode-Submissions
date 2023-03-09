/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
   
        if(head==NULL || head->next==NULL){
            return NULL;
        }


        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *ans = NULL;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast = fast->next->next;
            if(slow==fast){ 
                  break;
            }
        }

        if(slow!=fast){
            return NULL;   //No cyclic present:
        }
        else{
            //cyclic present:
            ListNode *p = head;
            while(p!=slow){
                p=p->next;
                slow=slow->next;
            }
            return p;
        }
    
    }
};
