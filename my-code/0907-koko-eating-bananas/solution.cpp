class Solution {
public:
   typedef long long ll;
   ll solve(int k,vector<int> &piles){
       ll hour=0;
       for(int i=0;i<piles.size();i++){
           int val = piles[i];
           if(val%k==0 && k!=0){
               hour+=val/k;
           }
           else{
               hour+=val/k+1;
           }
       }
       return hour;
   }


    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high = *max_element(piles.begin(),piles.end());
        while(low<=high){
            int k= low+(high-low)/2;
            if(solve(k,piles)<=h){
                 high = k-1;
            }
            else{
                low = k+1;
            }
        }
        return low;
    }
};
