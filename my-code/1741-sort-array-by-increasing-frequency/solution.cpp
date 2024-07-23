class Solution {
public:
   struct cmp{
    bool operator()(const pair<int,int> &a,const pair<int,int> &b){

          if(a.second==b.second){
            //same frequency:
            return a.first>b.first;
          }
          return a.second<b.second;

    
   }
   };
   
    vector<int> frequencySort(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }

        vector<pair<int,int>> vec(mp.begin(),mp.end());

        sort(vec.begin(),vec.end(),cmp());

        
         vector<int> ans;
        for(int i=0;i<vec.size();i++){
            pair<int,int> P = vec[i];
            int time = P.second;
            for(int j=1;j<=time;j++){
                ans.push_back(P.first);
            }
        }
        return ans;

    }
};
