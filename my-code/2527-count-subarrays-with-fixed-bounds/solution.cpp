class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;

        long long minpos = -1;
        long long maxpos = -1;
        long long calpit = -1;
        for(int i=0;i<nums.size();++i){
             
             if(nums[i]<minK || nums[i]>maxK){
                 calpit=i;
             }

             if(nums[i]==minK){
                 minpos = i;
             }
             if(nums[i]==maxK){
                 maxpos = i;
             }

             int smaller = min(minpos,maxpos);
             int temp = smaller-calpit;
             if(temp<=0){
                 ans+=0;
             }else{
                 ans+=temp;
             }

        }
        return ans;
    }
};
