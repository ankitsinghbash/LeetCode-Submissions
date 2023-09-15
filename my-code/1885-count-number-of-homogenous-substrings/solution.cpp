class Solution {
public:
    int const mod=1e9+7;
    typedef long long ll;
    int countHomogenous(string s) {
        ll total=0;
        ll cnt=1;
        for(int i=1;i<s.size();i++){
               if(s[i]==s[i-1]){
                   cnt++;
               }
               else{
                   ll val = cnt*(cnt+1)/2;
                   total+=val;
                   cnt=1;
               }
        }
        ll val = cnt*(cnt+1)/2;
        total+=val;
        return total%mod;
    }
};
