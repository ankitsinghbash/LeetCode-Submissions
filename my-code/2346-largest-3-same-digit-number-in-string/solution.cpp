class Solution {
public:
    string largestGoodInteger(string s) {
        char ans='\0';
        int maxx=0;
        for(int i=2;i<s.size();i++){
              if(s[i]==s[i-1] && s[i-1]==s[i-2]){
                    int val = s[i]-'0';
                    if(val>=maxx){
                        maxx=val;
                        ans = s[i];
                    }
              }
        }
        if(ans=='\0'){
            return "";
        }
        return string(3,ans);
    }
};
