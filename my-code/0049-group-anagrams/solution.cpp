class Solution {
public:
   
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
         unordered_map<string,vector<string>> mp;
         for(int i=0;i<strs.size();i++){
            string str = strs.at(i);
            sort(str.begin(),str.end());
            auto it = mp.find(str);
            if(it!=mp.end()){
                mp[str].push_back(strs[i]);  //not as mp[it] //imp:
            }
            else{
                mp[str];
                mp[str].push_back(strs[i]);
            }
        }

        vector<vector<string>> ans;
        for(auto x : mp){
            vector<string> sm;
            for(auto y : x.second){
                sm.push_back(y);
            }
            ans.push_back(sm);
        }
        return ans;
    
    }
};
