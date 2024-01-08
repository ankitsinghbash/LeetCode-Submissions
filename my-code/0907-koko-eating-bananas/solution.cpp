class Solution {
public:
    int solve(int speed,int h,vector<int> &piles){
        int myhour = 0;
        for(int i=0;i<piles.size();i++){
                if(piles[i]%speed==0){
                    myhour+=(piles[i]/speed);
                }
                else{
                    myhour+=(piles[i]/speed)+1;
                }
        }
        return myhour;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high  = *max_element(piles.begin(),piles.end())+1;
        int result=-1;
        while(low<high){
            int mid = low+(high-low)/2;  //mid is my speed:
            if(solve(mid,h,piles)<=h){
                high = mid;
                result = mid;
            }
            else{
                low = mid+1;
            }
        }
        return result;
    }
};
