class Solution {
public:
     int check(int cap,vector<int> &weights){
        int currsum = 0;
        int totalday = 0;
         int n = weights.size();
         for(int i=0;i<n;i++){
                if(weights[i]>cap){
                    return INT_MAX;
                }
               currsum+=weights[i];
               if(currsum==cap){
                   totalday++;
                   currsum=0;
               }
              if(currsum>cap){
                   totalday++;
                  currsum=0;
                  currsum = weights[i];
              }
          }
         if(currsum!=0){
               totalday++;
          }
         return totalday;

    }
    int shipWithinDays(vector<int>& weights, int days) {
        
        int low=1;
        int high =INT_MAX;
        int result = -1;
        while(low<high){
                 int mid = low+(high-low)/2;   //mycapacity:
                 if(check(mid,weights)<=days){
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
