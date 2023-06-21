class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i=0;i<nums1.size();i++){
            mp[nums1[i]]++;
        }
        
        
        for(int i=0;i<nums2.size();i++){
            int value = nums2[i];
            if(mp[value]>0){
                ans.push_back(value);
                mp[value]--;
            }
        }
        return ans;
    }
};
