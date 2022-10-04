class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>m;
        for(int i=0;i<nums1.size();i++) m[nums1[i]]++;
        set<int>s;
        for(int i=0;i<nums2.size();i++) s.insert(nums2[i]);
        vector<int>ans;
        for(auto x:s) if(m[x]>0) ans.push_back(x);
        return ans;
    }
};
