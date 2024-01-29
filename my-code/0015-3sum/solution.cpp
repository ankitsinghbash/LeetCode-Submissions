class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> store;
            set<vector<int>> st;
             sort(nums.begin(),nums.end());
             for(int i=0;i<=nums.size()-3;i++){
                 int j=i+1;
                 int k = nums.size()-1;
                 int val =  -nums[i];
                 vector<int> ans;
                 while(j<k){
                       if(nums[j]+nums[k]>val){
                           k--;
                       }
                       else if(nums[j]+nums[k]<val){
                               j++;
                       }
                       else if(nums[j]+nums[k]==val){
                            while(j<k && nums[j]==nums[j+1]){
                               j++;
                             }
                            while(j<k && nums[k]==nums[k-1]){
                                k--;
                            } 
                            ans.push_back(nums[i]);
                            ans.push_back(nums[j]);
                            ans.push_back(nums[k]);
                            j++;
                            k--;
                            st.insert(ans);
                            ans.clear();
                       }
                 }
             } 
             
             for(auto it = st.begin();it!=st.end();it++){
                 vector<int> val = *it;
                 store.push_back(val);
             }
             return store;
        
    }
};
