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



  
 
  ListNode *addlast(ListNode *&head,int data){
   
    ListNode *new_node = new ListNode;
    new_node->val=data;
    new_node->next=NULL;
    if(head==NULL){
        head = new_node;
    }
    else{
        ListNode *curr=head;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=new_node;
    }
   return head;
  }

   


   ListNode *solve(vector<int> &ans){
       ListNode *head = NULL;
       for(int i=0;i<ans.size();++i){
           addlast(head,ans[i]);
       }
       return head;
   }




    ListNode* deleteDuplicates(ListNode* head) {
        unordered_map<int,int> mp;
        ListNode *curr = head;
        while(curr!=NULL){
            mp[curr->val]++;
            curr=curr->next;
        }

        vector<int> ans;
       
        for(auto it=mp.begin();it!=mp.end();++it){
            if(it->second==1){
                ans.push_back(it->first);
            }
        }
         sort(ans.begin(),ans.end());
        return solve(ans);
    }
};
