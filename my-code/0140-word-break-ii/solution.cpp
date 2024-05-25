class Solution {
public:
    vector<string> store;
    void solve(int i,string s,unordered_set<string> &st,string ans){
       
         if(i>=s.size()){
            ans.pop_back();
            store.push_back(ans);
            return;
         }

         for(int idx=i;idx<s.size();idx++){
            string get_str = s.substr(i,idx-i+1);
            if(st.find(get_str)!=st.end()){
                  solve(idx+1,s,st,ans + get_str + ' '); //similar to Backtrack not execpt bracktrack://becuase recursion go to our latest last call:
            }
         }



    }


    vector<string> wordBreak(string s, vector<string>& wordDict) {
        string ans;
        unordered_set<string> st;
        for(int i=0;i<wordDict.size();i++){
            st.insert(wordDict[i]);
        }
        solve(0,s,st,ans);
        return store;


    }
};
