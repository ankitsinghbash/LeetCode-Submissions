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
    void add_element(ListNode *&head,int value,ListNode *&prev){
             if(head == NULL){
                 ListNode *new_node = new ListNode;
                 new_node->val = value;
                 new_node->next = NULL;
                 head  = new_node;
                 prev = head;
                 return;
             }
             else{
                 ListNode *new_node = new ListNode;
                 new_node->val = value;
                 new_node->next = NULL;
                 ListNode *temp = head;
                 temp->next =  new_node;
                 head = new_node;
             }

    }


     ListNode *solve(vector<int> &store){
         ListNode *head = NULL;
         ListNode *prev = NULL;
         for(int i=0;i<store.size();i++){
             add_element(head,store[i],prev);
         }

         return prev;
     }
      ListNode* sortList(ListNode* head) {
        //brute force:
        vector<int> store;
        ListNode *temp = head;
        while(temp!=NULL){
            store.push_back(temp->val);
            temp=temp->next;
        }
        sort(store.begin(),store.end());

        //I juse make a linked list for this store vector<int> and return the head of this linkedlist:
        ListNode *head1 = solve(store);
        return head1;
       
    }
};
