class Solution {
public:
   vector<vector<int>> ans;
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(),nums1.end());
        unordered_set<int> s2(nums2.begin(),nums2.end());
        
        vector<int> first;
        vector<int> second;
        int n = nums1.size();
        for(auto it = s1.begin();it!=s1.end();it++){
            auto it2 = s2.find(*it);
            if(it2==s2.end()){
                first.push_back(*it);
            }
        }

         for(auto it = s2.begin();it!=s2.end();it++){
            auto it2 = s1.find(*it);
            if(it2==s1.end()){
                second.push_back(*it);
            }
        }
        ans.push_back(first);
        ans.push_back(second);
        return ans;

    }
};
