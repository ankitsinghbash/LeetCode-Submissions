class Solution {
public:
    bool solve(string str){
        unordered_map<char,int> mp;
        for(int i=0;i<str.size();i++){
            char ch = str[i];
            mp[ch]++;
        }
        for(int i=0;i<str.size();i++){
            char ch = str[i];   //a
            if(ch==tolower(ch)){
                  //a:
                  char ch1 = toupper(ch);
                  auto it = mp.find(ch1);
                  if(it==mp.end()){
                      return false;
                  }
                  if(it!=mp.end()){
                      mp[ch]--;
                      mp[ch1]--;
                  }
            }
            else if(ch==toupper(ch)){
                 //A:
                 char ch1 = tolower(ch);
                 auto it = mp.find(ch1);
                 if(it==mp.end()){
                     return false;
                 }
                 if(it!=mp.end()){
                     mp[ch]--;
                     mp[ch1]--;
                 }
            }
        }
        return true;
    }

    string longestNiceSubstring(string s) {
        string result="";
        for(int i=1;i<=s.size();i++){
            for(int j=0;j<=s.size()-i;j++){
                string str = s.substr(j,i);
                bool flag = solve(str);
                if(flag==true && str.size()>result.size()){
                    result = str;
                }
            }
        }
        return result;
    }
};
