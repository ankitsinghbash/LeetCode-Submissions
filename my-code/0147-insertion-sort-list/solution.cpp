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
    ListNode* insertionSortList(ListNode* head) {
        //two approach first assign all value in array then sort linked list then agian assign all value in the linked list:
        //method 2: Direct sort the linked list:
        ListNode *nxt = head->next;
        while(nxt!=NULL)
        {
            ListNode *current = head;
            while(current!=nxt)
            {
              if(nxt->val<current->val)
              {
                  swap(current->val,nxt->val);
              }
              current=current->next;
            }
            nxt=nxt->next;
        }
        return head;
    }
};
