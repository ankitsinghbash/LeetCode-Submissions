class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> mp;
        int n = target.size();
        for(int i=0;i<n;i++){
             mp[target[i]] += arr[i];
        }

        for(int i=0;i<arr.size();i++){
              auto it = mp.find(arr[i]);
              if(it==mp.end()){
                return false;
              }
              else{
                mp[arr[i]]--;
                if(mp[arr[i]]==0){
                   mp.erase(it);
                }
              }
        }
        return true;
    }
};
