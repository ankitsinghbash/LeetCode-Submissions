class Solution {
public:
    int pivotInteger(int n) {
        int total = n*(n+1)/2;
        int curr_sum=0;
        for(int i=1;i<=n;i++){
              curr_sum+=i;
              if(curr_sum==total-curr_sum+i){
                return i;
              }
        }
        return -1;
    }
};
