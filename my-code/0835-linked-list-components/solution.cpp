
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
         unordered_set<int> st;
     
         for(auto &x : nums){
            st.insert(x);
         }

         int component=0;
         int ans=0;
         ListNode *temp = head;
         while(temp!=NULL){
             if(st.find(temp->val)==st.end()){
                //not present:
                ans+=component;
                component = 0;
             }
             else if(temp->next==NULL && st.find(temp->val)!=st.end()){
                ans+=1;
             }
             else{
                 component = 1;
             }
             temp=temp->next;
         }
         return ans;


    }
};
