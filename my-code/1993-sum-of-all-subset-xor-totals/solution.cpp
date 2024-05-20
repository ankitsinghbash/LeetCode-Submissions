class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int time = pow(2,n);
        int total=0;
        for(int i=0;i<time;i++){
              int curr_sum=0;
              for(int j=0;j<n;j++){
                    if((i&(1<<j))==0){
                         curr_sum=curr_sum^nums[j];
                    }
              }
              total+=curr_sum;

        } 
        return total;
    }
};
