class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int> mp;
        for(int i=0;i<nums1.size();i++){
            int idx = nums1[i][0];
            int val = nums1[i][1];
            mp[idx]=val;
        }
        
        for(int i=0;i<nums2.size();i++){
            int idx1 =  nums2[i][0];
            int val1 = nums2[i][1];
            if(mp.find(idx1)!=mp.end()){
                //present;
                mp[idx1]+=val1;
            }
            else{
                mp[idx1]=val1;
            }
        }
        vector<vector<int>> real;
        for(auto it=mp.begin();it!=mp.end();++it){
            vector<int> sm;
            int index = it->first;
            int value = it->second;
            sm.push_back(index);
            sm.push_back(value);
            real.push_back(sm);
            sm.clear();
        }
        return real;
        
    }
};
