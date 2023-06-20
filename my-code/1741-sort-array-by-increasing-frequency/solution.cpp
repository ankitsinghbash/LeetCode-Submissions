class Solution {
public:
    vector<int> ans;
    static bool cmp(pair<int,int> a,pair<int,int> b){

        if(a.second!=b.second){
            return a.second<b.second;
        }
        else{
            if(a.second==b.second){
                return a.first>b.first;
            }
        }
      return false;

    }


   

    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

       vector<pair<int,int>> store;
       for(auto it=mp.begin();it!=mp.end();it++)
       {
           store.push_back({it->first,it->second});
       }

       sort(store.begin(),store.end(),cmp);
       for(int i=0;i<store.size();i++){
           pair<int,int> P = store[i];
           int value = P.first;
           int time = P.second;
           for(int i=0;i<time;i++){
                ans.push_back(value);
           }
       }
       return ans;

    }
};
