class Solution {
public:
 
   long long  find_candies(int mid,vector<int> &candies){
       long long  cnt=0;
       for(int i=0;i<candies.size();++i){
            cnt+=candies[i]/mid;
       }
       return cnt;
   }


    int maximumCandies(vector<int>& candies, long long k) {
        int low=1;
        int high = *max_element(candies.begin(),candies.end());
        //int ans=0;
        while(low<=high){
             long long  mid = low+(high-low)/2;
             if(find_candies(mid,candies)<k){
                      high = mid-1;
             }
             else
              {
                    //  ans=mid;
                      low=mid+1;
              }

        }
        return low-1;
    }
};
