class Solution {
public:
   
   double Ishour(int mid , vector<int> &dist){
        double total  =0;
        for(int i=0;i<dist.size();i++){
            int value = dist[i];
            int data  = value/mid;
            if(i!=dist.size()-1){
            if(value%mid==0){
                total+=data;
            }
            else{
                total+=data+1;
            }
            }else{
                double data = (double)(value)/(double)(mid);
                total+=data;
            }
        }
        return total;
   }



    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low=1;
        int high = 1e9;
        int result = -1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(Ishour(mid,dist)<=hour){
                result = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return result;
    }
};
