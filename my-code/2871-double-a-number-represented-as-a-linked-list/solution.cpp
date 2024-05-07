
class Solution {
public:
    ListNode *reverse(ListNode *head,ListNode *prev){
       if(head==NULL) return prev;

       ListNode *temp = head->next;
       head->next =  prev;
       return reverse(temp,head);

    }
    ListNode* doubleIt(ListNode* head) {
        //just Direct multiple the value:
        ListNode *head1 = reverse(head,NULL);
        ListNode *dummy = new ListNode(-1);
        ListNode *prev = dummy;

        int carry=0;
        ListNode *temp = head1;
        while(carry>0 || temp!=NULL){
            int value;
            if(temp==NULL){
                value=0;
            }
            else{
                value = temp->val;
                 temp=temp->next;
            }
            int curr_value = value*2+carry;
            int rem = curr_value%10;
            ListNode *new_node = new ListNode(rem);
            prev->next = new_node;
            prev = new_node;
            carry = curr_value/10;
           
        }
        prev->next=NULL;
        ListNode *head2 = reverse(dummy->next,NULL);
        return head2;




    }
};
