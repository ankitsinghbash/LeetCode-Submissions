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
   
    ListNode * reverse(ListNode* head){
    ListNode* curr=head,*prev=NULL,*nex=NULL;
    while(curr){
        nex=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nex;
    }
    return prev;
}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* rev1=l1;
    ListNode* rev2=l2;
    ListNode* dummy=NULL;
    ListNode* p=dummy;
    ListNode* m=dummy;
    int carry=0;
    while(rev1 || rev2 || carry!=0){
        int x=carry;
        if(rev1){
            x+=rev1->val;
        }
        if(rev2){
            x+=rev2->val;
        }
        
        ListNode* nn=new ListNode(x%10);
        nn->next=dummy;
        dummy=nn;
        carry=x/10;
        if(rev1)
            rev1=rev1->next;
        if(rev2)
            rev2=rev2->next;
    
    }
    
    return reverse(dummy);

    }
};
