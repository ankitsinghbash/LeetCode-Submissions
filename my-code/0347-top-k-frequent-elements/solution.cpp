class Solution {
public:
   typedef pair<int,int> P;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        
         priority_queue<P> pq;
         for(auto it=mp.begin();it!=mp.end();it++){
             pq.push({it->second,it->first});
         }

         vector<int> ans;
         while(pq.size()>0 && k--){
             pair<int,int> Pair = pq.top();
             pq.pop();
             ans.push_back(Pair.second);
         }
         return ans;
         

    }
};
