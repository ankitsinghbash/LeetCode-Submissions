class Solution {
public:
    int maxScore(string s) {
        int total_one = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1') total_one++;
        }
        int currone=0;
        int currzero=0;
        int maxx=INT_MIN;
        for(int i=0;i<s.size()-1;i++){
                if(s[i]=='0'){
                    currzero++;
                }
                else{
                    currone++;
                }
                int restone = total_one-currone;
                int ans = currzero+restone;
                maxx =max(maxx,ans);
        }
        return maxx;
    }
};
