class Solution {
public:
    ListNode *reverse(ListNode *head,ListNode *prev){

       if(head==NULL){
           return prev;
       }


       ListNode *temp = head->next;
       head->next = prev;//
       return reverse(temp,head);
   }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) {
            return head;
        }

        ListNode* temp = head;
        ListNode* prev = nullptr;
        int cnt = 1;
        ListNode* knowledge1 = nullptr;
        ListNode* knowledge2 = nullptr;
        ListNode* alpha1 = nullptr;
        ListNode* alpha2 = nullptr;

        while (temp != nullptr) {
            if (cnt == left) {
                knowledge1 = prev;
                knowledge2 = temp;
            }
            if (cnt == right) {
                alpha1 = prev;
                alpha2 = temp;
            }
            cnt++;
            prev = temp;
            temp = temp->next;
        }

        ListNode* last = alpha2->next;
        if (knowledge1 != nullptr) {
            knowledge1->next = nullptr;
        }
        alpha2->next = nullptr;
        ListNode* k = reverse(knowledge2, nullptr);
        if (knowledge1 != nullptr) {
            knowledge1->next = k;
        } else {
            head = k;
        }
        knowledge2->next = last;
        return head;
    }
};

 
