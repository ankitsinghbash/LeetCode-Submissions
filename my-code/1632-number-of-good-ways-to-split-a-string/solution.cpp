class Solution {
public:
    int numSplits(string s) {
        unordered_map<char,int> mp1,mp2;
        //mp1 for first store and mp2 for second store:
        for(int i=0;i<s.size();i++){
            mp1[s[i]]++;
        }
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(mp1[s[i]]==1){
                mp1.erase(s[i]);
            }
            else{
                mp1[s[i]]--;
            }
            mp2[s[i]]++;
            if(mp1.size()==mp2.size()){
                cnt++;
            }
        }
        return cnt;
    }
};
