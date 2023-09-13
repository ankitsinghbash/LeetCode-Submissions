class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(p.size()>s.size()){
            return ans;
        }
        vector<int> window_p(26,0);
        vector<int> window_s(26,0);
        for(int i=0;i<p.size();i++){
            window_p[p[i]-'a']++;
            window_s[s[i]-'a']++;
        }
        if(window_p==window_s){
            ans.push_back(0);
        }

       
       int x = p.size();
       for(int i=p.size();i<s.size();i++){
           window_s[s[i-x]-'a']--;
           window_s[s[i]-'a']++;
           if(window_s==window_p){
               ans.push_back(i-x+1);
           }
       }
       return ans;  
    }
};
