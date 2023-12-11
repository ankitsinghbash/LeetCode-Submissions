class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int time = n/4;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        
        for(auto it = mp.begin();it!=mp.end();it++){
            if(it->second>time){
                return it->first;
            }
        }
        return 0;
    }
};
