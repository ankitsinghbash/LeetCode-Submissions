class Solution {
public:
    string lastNonEmptyString(string s) {
        int maxx_cnt=0;
        vector<int> alpha(26,0);
        for(int i=0;i<s.size();i++){
            int idx = s.at(i)-'a';
            alpha[idx]++;
        }
        for(int i=0;i<26;i++){
            int cnt = alpha[i];
            maxx_cnt = max(maxx_cnt,cnt);
        }
        
         string ans="";
        for(int i=s.size()-1;i>=0;i--){
               char ch = s.at(i);
               int idx = ch-'a';
               if(alpha[idx]==maxx_cnt){
                   ans=ch+ans;
                   alpha[idx]=0;
               }
        }
     
        return ans;
        
    }
};


