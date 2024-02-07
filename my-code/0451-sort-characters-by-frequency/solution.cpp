class Solution {
public:
    struct cmp{
         bool operator()(pair<char,int> &a,pair<char,int> &b) const{
             
                return a.second>b.second;
         }
    };

    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
       
        vector<pair<char,int>> vec(mp.begin(),mp.end());
        sort(vec.begin(),vec.end(),cmp());
        string ans="";
        for(int i=0;i<vec.size();i++){
            char ch = vec[i].first;
            int time = vec[i].second;
            while(time--){
                ans+=ch;
            }
        }
       return ans;
    }
};
