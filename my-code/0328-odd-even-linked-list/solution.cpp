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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL){
            return NULL;
        }

        ListNode* odded  = head;
        ListNode* evened = head -> next;
        ListNode* evenhead = head -> next;
        
        while(evened != NULL and evened -> next != NULL){
            // put odd to the odd list
            odded ->next = odded -> next -> next;
            // Move the pointer to the next odd
            odded = odded -> next;
        
            // put even to the even list
            evened -> next = evened -> next -> next;
            // Move the pointer to the next even
            evened = evened -> next;
        }
        odded -> next = evenhead;
        return head;    
    }
};
