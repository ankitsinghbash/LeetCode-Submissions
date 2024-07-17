class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
           ListNode *temp = head;
         unordered_set<int> st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        
         ListNode *dummy = new ListNode(-1);
         ListNode *dummy1 = dummy;
          while(temp!=NULL){
               ListNode *node = temp;
               while(node!=NULL && st.find(node->val)!=st.end()){
                      node = node->next;
               }
              dummy->next = node;
              temp = node;    
              dummy = temp;
              if(temp==NULL){
                  break;
              }
              temp = temp->next;
              
             
          }
        return dummy1->next;
    }
};
