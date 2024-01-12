class Solution {
public:
    bool check(char ch){
        if(ch=='a' || ch=='e' || ch=='i' ||ch=='o'||ch=='u'||ch=='A' ||ch=='E'||ch=='I'||ch=='O'||ch=='U'){
            return true;
        }
        return false;
    }
    bool halvesAreAlike(string s) {
        int cnt=0;
        for(int i=0;i<s.size();i++){
            char ch  = s[i];
            if(check(ch)){
                cnt++;
            }
        }
         
        int cnt2=0;
        for(int i=0;i<s.size()/2;i++){
            char ch = s[i];
            if(check(ch)){
                cnt2++;
            }
        }
        int val = 2*cnt2-cnt;
        if(val==0) return true;
        return false;
       
    }
};
