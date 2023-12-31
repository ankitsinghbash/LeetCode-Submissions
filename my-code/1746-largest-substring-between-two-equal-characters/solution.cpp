class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        //char vector:
        vector<int> alpha(26,0);
        for(int i=0;i<s.size();i++){
             int idx  = s.at(i)-'a';
             alpha[idx]=i;
        }
        int maxx=INT_MIN;
        for(int i=0;i<s.size();i++){
             char ch = s.at(i);
             int idx = ch-'a';
             int val = alpha[idx];
             int len = val-i-1;
            maxx = max(maxx,len);
        }
        if(maxx==INT_MIN) return -1;
        return maxx;
    }
};
