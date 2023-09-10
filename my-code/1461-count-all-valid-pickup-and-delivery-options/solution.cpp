class Solution {
public:
  typedef long long ll;
  ll const mod = 1e9+7;
   ll solve(ll n){
        if(n==1){
            return 1;
        }
        else if(n==2){
            return 6;
        }


       ll counter=0;
       ll space = 2*n-1;
       ll total = space*(space+1)/2;
       counter+=total*solve(n-1);
       return (ll)counter%mod;

   }

    int countOrders(int n) {
        //recursive code:
        return solve(n);
    }
};
