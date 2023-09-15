class Solution {
public:
    typedef long long ll;
    const ll mod = 1e9+7;
    int numSub(string s) {
        //count continue substring:
        ll total=0;
        ll cnt=0;
        ll mod = 1e9 + 7; // Define the modulo value

        for(int i=0;i<s.size();i++){
             if(s[i]=='1'){
                 cnt++;
             }
             else{
                 //check:
                 ll val = cnt*(cnt+1)/2;
                 total += val;
                 cnt=0;
             }
        }
        ll val = cnt*(cnt+1)/2;
        total += val;

        // Apply modulo operation to the total
        return total % mod;
    }
};

