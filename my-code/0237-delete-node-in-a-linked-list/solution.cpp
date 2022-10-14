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
    void deleteNode(ListNode* node) {
       node->val=node->next->val;
       node->next=node->next->next;
    }
};


/*



 ListNode *prev=NULL;
       ListNode *temp = head;
        while(temp!=NULL&&temp->next!=NULL)
        {
            if(temp->val==node->val)
            {
                break;
            }
            prev=temp;
            temp=temp->next;
        }
        //temp is the current node jo ki delete karni hai:
        prev->next=temp->nex
        */
