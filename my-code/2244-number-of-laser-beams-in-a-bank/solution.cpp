class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
           int ans=0;
           int prev=0;
           for(int i=0;i<bank.size();i++){
               string str = bank[i];
               int cnt = 0;

               for(int j=0;j<str.size();j++){
                   if(str[j]=='1'){
                       cnt++;
                   }
               }

               int val = prev*cnt;
               if(cnt!=0){
                prev  = cnt;
               }
               ans+=val;
           }
           return ans;
    }
};
