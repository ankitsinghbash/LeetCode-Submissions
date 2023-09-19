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

   bool isPossible(vector<int>& dist, double hour, int speed) {
        double time = OK(speed,dist);
        return time <= hour;
    }



    int minSpeedOnTime(vector<int>& dist, double hour) {
        
        int low = 0;
        int high = 1e7;

        if (!isPossible(dist, hour, high)) {
            return -1;
        }

        while(low<=high){
            int mid = low+(high-low)/2;
            if(OK(mid,dist)<=hour){
                high=mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};
