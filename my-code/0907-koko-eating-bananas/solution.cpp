class Solution {
public:
   long long  Hours(int mid,vector<int> &piles){
       long long total=0;
       int n = piles.size();
       for(int i=0;i<piles.size();++i){
             int val = piles[i]/mid;
             total+=val;
             if(piles[i]%mid!=0){
                 total+=1;
             }
        }
       return total;
   }
  

    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high = *max_element(piles.begin(),piles.end());
        int result = 1;
        while(low<high){
            int mid = low+(high-low)/2;
            if(Hours(mid,piles)<=h){
                high = mid;
            }
            else{
                low = mid+1;
                result = low;
            }
        }
        return  result;
    }
};
