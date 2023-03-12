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
    vector<int> ans;

 
   ListNode *addlast(ListNode *&head,int data){
       ListNode *new_node = new ListNode;
       new_node->val=data;
       new_node->next=NULL;
       if(head==NULL){
           head=new_node;
       }
       else{
           ListNode *temp = head;
           while(temp->next!=NULL){
               temp=temp->next;
           }
           temp->next=new_node;
       }
       return head;
   }

    
    ListNode *solve(vector<int> &ans){
        ListNode *head=NULL;
        for(int i=0;i<ans.size();i++){
            addlast(head,ans[i]);
        }
        return head;
    }



    ListNode* mergeKLists(vector<ListNode*>& lists) {
         for(auto &x : lists){
             ListNode *curr = x ;
             while(curr!=NULL){
                 ans.push_back(curr->val);
                 curr=curr->next;
             }
         }
         sort(ans.begin(),ans.end());
         return solve(ans);
    }
};
