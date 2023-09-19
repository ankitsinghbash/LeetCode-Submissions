class Solution {
public:
   long long find(vector<int> &ranks,long long time){
       long long sum = 0;
       for(auto &x : ranks){
           sum+=(long long)int(sqrt(1.0*time/x));
       }
       return sum;
   }

    long long repairCars(vector<int>& ranks, int cars) {
        long long  low = 1,high = 1L * ranks[0] * cars * cars;;
        while(low<=high){
           long long  mid = low+(high-low)/2;
          if(find(ranks,mid)>=cars){
              high = mid-1;
          }
          else{
              low = mid+1;
          }
        }
        return low;
    }
};
