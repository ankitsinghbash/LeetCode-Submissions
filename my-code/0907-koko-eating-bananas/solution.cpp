class Solution {
public:

   long long  find_banana(int mid,vector<int> &piles){
        long long ans=0;
        for(int i=0;i<piles.size();++i){
             int val = piles[i]/mid;
             ans+=val;
             if(piles[i]%mid!=0){
                 ans+=1;
             }
        }
       return ans;
   }
   


    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high = *max_element(piles.begin(),piles.end());

     //   int result=-1;
        while(low<=high){
            int mid = low+(high - low)/2;
            if(find_banana(mid,piles)<=h){
                 high = mid-1;
            }
            else{
                 low = mid+1;
            }
        }
        return low;
    }
};
