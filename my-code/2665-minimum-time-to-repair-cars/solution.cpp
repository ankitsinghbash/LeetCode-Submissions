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
        long long  low = 0;
        long long maxx = *max_element(ranks.begin(),ranks.end());
        long long  high = (long long )maxx * (long long )cars * (long long )cars;
        while(low<high){
           long long  mid = low+(high-low)/2;
           if(find(ranks,mid)<cars){
              low=mid+1;
           }
           else{
               high = mid;
           }
        }
        return low;
    }
};
