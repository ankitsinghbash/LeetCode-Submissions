class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
         unordered_map<string,int> mp;
        for(auto x:words){
            string y = x;
            reverse(y.begin(),y.end());
            if(x!=y){
            mp[x]++;
            mp[y]++;
            }
        }
        
        
        int cnt1=0;
      //  unordered_map<string,int> iterator :: it;
        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->second==2){
                cnt1++;
            }
        }
        
        // int cnt2=0;
        // for(int i=0;i<words.size();i++){
        //     string str = words[i];
        //     if(str[0]==str[1]){
        //         cnt2++;
        //     }
        // }
        
        int ans = cnt1/2;
        return ans;
    }
};
