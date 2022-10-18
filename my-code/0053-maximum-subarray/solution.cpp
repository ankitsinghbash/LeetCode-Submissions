class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int max=INT_MIN,sum=0,i,size=nums.size();
    for(i=0;i<size;i++){
        sum+=nums[i];
        if(max<sum)
            max=sum;
        if(sum<0)
            sum=0;
    }
    return max;
}
};
