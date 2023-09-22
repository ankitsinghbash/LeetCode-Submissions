class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        unordered_map<string,int> mp;
        if(s.size()<10){
          return {};
        }
        for(int i=0;i<=s.size()-10;i++){
            string str = s.substr(i,10);
            mp[str]++;
        }
       
       for(auto it = mp.begin();it!=mp.end();it++){
         if(it->second>1){
            ans.push_back(it->first);
         }
       }
       return ans;

    }
};
