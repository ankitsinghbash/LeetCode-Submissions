class Solution {
public:

    void solve(unordered_map<string,int> &mp,string s1){
        string str="";
        for(char ch : s1){
            if(ch==' '){
                mp[str]++;
               str="";
            }
            else{
               str+=ch;
            }
        }
        mp[str]++;

    }

    vector<string> uncommonFromSentences(string s1, string s2) {
       unordered_map<string,int> mp;
       solve(mp,s1);
       solve(mp,s2);

       vector<string> ans;
       for(auto it=mp.begin();it!=mp.end();++it){
           if(it->second==1){
               ans.push_back(it->first);
           }
       }
       return ans;
    }
};
