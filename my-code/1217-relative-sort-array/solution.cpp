class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i=0;i<arr1.size();i++){
            mp[arr1[i]]++;
        }

      
        for(int i=0;i<arr2.size();i++){
            int value = arr2[i];
            int time = mp[value];
            for(int i=0;i<time;i++){
                ans.push_back(value);
            }
            // auto it = mp.find(value);
            mp.erase(value);//or
            // mp.erase(it);

        }

        vector<int> temp;
        for(auto it = mp.begin();it!=mp.end();it++){
            int time = it->second;
            for(int i=0;i<time;i++){
                temp.push_back(it->first);
            }
        }
        sort(temp.begin(),temp.end());
        for(auto x : temp){
            ans.push_back(x);
        }
        return ans;
    }
};
