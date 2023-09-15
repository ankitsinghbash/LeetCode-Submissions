class Solution {
public:
    int maxPower(string s) {
        int maxx=0;
        int cnt=1;
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){
                cnt++;
            }
            else{
                if(cnt>maxx){
                    maxx = cnt;
                }
                cnt=1;
            }
        }
        if(cnt>maxx){
            maxx = cnt;
        }
        return maxx;
    }
};
