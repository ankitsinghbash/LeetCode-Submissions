class Solution {
public:
    double check(int speed,vector<int> &dist){
             double hour = 0.0;
             for(int i=0;i<dist.size();i++){
                 if(i==dist.size()-1){
                     double val = (dist[i]/(double)speed);
                     hour+=val;
                     break;
                 }
                 double val = ceil(dist[i]/(double)speed);
                 hour+=val;
             }
             return hour;

    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low=1;
        int high = 100000001;
        int result  = -1;
        while(low<high){
            int mid = low+(high-low)/2;
            if(check(mid,dist)<=hour){
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
