class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        //base case:
        


        ListNode *realhead = list1;
        ListNode *temp = list1;
        
        ListNode *temp_start = list1;
        ListNode *last = NULL;
        ListNode *list1_last = NULL;
        int start=0;
        while(temp_start!=NULL){
               if(start==b){
                   list1_last = temp_start->next;
                 //  temp_start->next = NULL;
               }
               start++;
               temp_start=temp_start->next;
        }
     

        
        int len=0;
        ListNode *temp2 = NULL;
        while(temp!=NULL){
            if(len==a-1){
                ListNode *second_start = list2;
              //  temp->next=NULL;
                temp->next=second_start;
                temp2 = second_start;
                while(temp2->next!=NULL){
                    temp2=temp2->next;
                }
               break;
            }
            temp=temp->next;
            len++;
        }
        temp2->next = list1_last;
        return realhead;
    }
};
