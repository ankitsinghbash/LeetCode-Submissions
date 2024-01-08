class Solution {
public:
    long long  check(int mid,vector<int> &candies){
       long long  cnt=0;
       for(int i=0;i<candies.size();++i){
            cnt+=candies[i]/mid;
       }
       return cnt;
   }

    int maximumCandies(vector<int>& arr, long long k) {
        int low=0;
        int high = *max_element(arr.begin(),arr.end());
        int result = 0;
        while(low<high){
             int mid = (low+high+1)/2;
             if(check(mid,arr)>=k){
                 low = mid;
                 result = mid;
             }
            else{
                high = mid-1;
            }
           }
        return result;
      }
    
};
