class Solution {
public:
    
    ListNode *reverse_LL(ListNode *head,ListNode *prev){
        
         if(head==NULL) return prev;
 
         ListNode *temp = head->next;
         head->next = prev;
         return reverse_LL(temp,head);

    }
    
    bool isPalindrome(ListNode* head) {
        ListNode *temp1 = head;

        ListNode *slow = head;
        ListNode *fast = head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow = slow->next;
        }

        ListNode *second_half = NULL;
        if(fast==NULL){
            second_half = slow;
        }
        else{
            second_half = slow->next;
        }
        

        ListNode *temp2 = reverse_LL(second_half,NULL);

        while(temp2!=NULL){
            if(temp1->val!=temp2->val){
                return false;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return true;
    }
};
