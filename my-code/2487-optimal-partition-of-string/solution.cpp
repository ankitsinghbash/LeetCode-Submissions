class Solution {
public:
    int partitionString(string s) {
         map<char,int> mp;
        int cnt = 0;
        for(int i=0;i<s.size();i++){
               char ch = s.at(i);
               auto it = mp.find(ch);
               if(it==mp.end()){
                   mp[ch]++;
               }
               else{
                   cnt++;
                   mp.clear();
                   mp[ch]++;
               }
        }
        cnt++;
        return cnt;
    }
};
