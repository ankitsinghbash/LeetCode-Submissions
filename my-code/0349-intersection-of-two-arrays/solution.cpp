class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i=0;i<nums1.size();i++){
            mp[nums1[i]]++;
        }

       set<int> s;
       for(int i=0;i<nums2.size();i++){
           s.insert(nums2[i]);
       } 

       for(auto it = s.begin();it!=s.end();it++){
           int value = *it;
           if(mp[value]>0){
               ans.push_back(value);
               mp[value]--;
           }
       }
     
      
      

       return ans;
    }
};
