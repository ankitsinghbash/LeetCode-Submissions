class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            int val = arr[i];
            mp[val]=i;
        }
        for(int i=0;i<arr.size();i++){
            int val = 2*arr[i];
            auto it = mp.find(val);
            if(it!=mp.end() && it->second!=i){
                return true;
            }
        }
        return false;
    }
};
