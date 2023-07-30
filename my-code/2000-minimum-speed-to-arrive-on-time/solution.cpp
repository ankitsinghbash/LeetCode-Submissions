class Solution {
public:
   double OK(int mid,vector<int> &dist){
       //mid is speed:
       double time = 0;
       for(int i=0;i<dist.size();i++){
         double y = double(dist[i])/mid;
         if(i==dist.size()-1){
             time+=y;
         }
         else{
             time+=ceil(y);
         }
       }
      return time;
   }



    int minSpeedOnTime(vector<int>& dist, double hour) {
      
        int low = 0;
        int high = 1e7;
        int result = -1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(OK(mid,dist)<=hour){
                result = mid;
                high=mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return result;
    }
};
