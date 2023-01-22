class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp;
        for(int i=0;i<nums2.size();i++){
            mp[nums2[i]]++;
        }
        
        for(int i=0;i<nums1.size();i++){
            int val = nums1[i];
            if(mp.find(val)!=mp.end()){
                return val;
            }
        }
        return -1;
        
       
        
        
        
        
    }
};
