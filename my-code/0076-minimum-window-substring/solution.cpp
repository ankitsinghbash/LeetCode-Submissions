class Solution {
public:
    string minWindow(string s, string t) {
             unordered_map<char,int> mp1,mp2;  //1 for s and 2 for t:
             for(int i=0;i<t.size();i++){
                 mp2[t[i]]++;
             }
 
             int start=0;
             int maxx = INT_MAX;

             int right=0;
             int cnt=0;
             int left=0;
             while(right<s.size()){
                    char ch = s[right];

                    if(mp2.count(ch)==0){
                        right++;
                        continue;
                    }
        
                   
                    if(mp1[ch]<mp2[ch]) cnt++;
                    //if ch is present in mp2:
                    mp1[ch]++;

                    if(cnt==t.size()){
                           //shrink:
                           while(mp2.count(s[left])==0 || mp1[s[left]]>mp2[s[left]]){
                               if(mp1[s[left]]>0){
                                   mp1[s[left]]--;
                               }
                               left++;
                           }

                          
                          if(maxx>right-left+1){
                              start = left;
                               maxx = right-left+1;
                          }
                    }
                  right++;
             }

             return maxx==INT_MAX ? "" : s.substr(start,maxx);
    }
};
