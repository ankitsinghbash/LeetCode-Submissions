class Solution {
public:
    bool check_arth(int start,int end,vector<int> &nums){
           vector<int> store;
           for(int i=start;i<=end;i++){
               store.push_back(nums[i]);
           }

           if(store.size()==1){
               return false;
           }

           if(store.size()==2){
               return true;
           }


           sort(store.begin(),store.end());
          
           int D = store[1]-store[0];
           for(int i=2;i<store.size();i++){
                int diff = store[i]-store[i-1];
                if(diff!=D){
                    return false;
                }
           }
           return true;

    }

    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        int n=l.size();
        for(int i=0;i<n;i++){
            int start  = l[i];
            int end = r[i];
            bool check  = check_arth(start,end,nums);
            ans.push_back(check);
        }
        return ans;

    }
};
