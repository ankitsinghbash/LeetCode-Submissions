class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]=i;
        }
        int size = mp.size();
        auto it = mp.begin();
        for(int i=1;i<size;i++){
            it++;
        }
        return it->second;
    }
};
