class Solution {
public:
    ListNode* reverse(ListNode *&head, ListNode *prev) {
        if (head == NULL) return prev;
        
        ListNode *nextNode = head->next;
        head->next = prev;
        return reverse(nextNode, head);
    }

    ListNode* removeNodes(ListNode* head) {
        ListNode *reversedHead = reverse(head, NULL);
        ListNode *prev = reversedHead;
        ListNode *temp = reversedHead->next;
        
        while (temp != NULL) {
            if (temp->val < prev->val) {
                temp=temp->next;
            } else {
               prev->next = temp;
               prev = temp;
               temp = temp->next;
            }
        }
        prev->next = NULL;
        return reverse(reversedHead, NULL);
    }
};

