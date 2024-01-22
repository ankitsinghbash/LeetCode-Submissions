class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2,0);
        unordered_set<int> st1(nums.begin(),nums.end());
        for(int i=1;i<=nums.size();i++){
            auto it = st1.find(i);
            if(it==st1.end()){
                ans[1]=i;
                break;
            }
        }

       
       unordered_map<int,int> mp;
       for(int i=0;i<nums.size();i++){
           mp[nums[i]]++;
       }
       for(auto it = mp.begin();it!=mp.end();it++){
           if(it->second==2){
               ans[0]=it->first;
               break;
           }
       }
       return ans;

    }
};
