class Solution {
public:
    ListNode *solve(ListNode *head,ListNode *prev){
       
        if(head==NULL) return prev;
        

        ListNode *temp = head->next;
        head->next = prev;
        return solve(temp,head);
    }

    ListNode* reverseList(ListNode* head) {
        return solve(head,NULL);
    }
};
