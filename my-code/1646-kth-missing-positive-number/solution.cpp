class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();++i){
            mp[arr[i]]++;
        }
        vector<int> ans;
        int i=1;
        while(k!=0){
            auto it = mp.find(i);
            if(it==mp.end()){
                ans.push_back(i);
                k--;
            }
            i++;
        }
        return ans[ans.size()-1];
    }
};
