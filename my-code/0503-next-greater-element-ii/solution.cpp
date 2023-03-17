class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
       vector<int> store;
       for(int i=0;i<nums.size();i++){
           store.push_back(nums[i]);
       } 
       for(int i=0;i<nums.size();i++){
           store.push_back(nums[i]);
       }
       int n=nums.size()*2;
       int new_arr[n];
       for(int i=0;i<store.size();i++){
           new_arr[i]=store[i];
       }

        stack<int> st;
      
        int ans[n];

        for(auto &x : new_arr){
            cout<<x<<" ";
        }   
       cout<<endl;
     
        st.push(new_arr[n-1]);
        ans[n-1]=-1;
        
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && new_arr[i]>=st.top()){
                st.pop();
            }
            if(st.empty()){
                ans[i]=-1;
            }
            else{
                ans[i]=st.top();
            }
            st.push(new_arr[i]);
        }

       for(auto &x : ans){
           cout<<x<<" ";
       }
     

        vector<int> result;
        for(int i=0;i<nums.size();i++){
            result.push_back(ans[i]);
        }
        return result;
    }
};
