class Solution {
public:
    void sortColors(vector<int>& nums) {
             int i=0;   //for 0
             int j=0;   //for 1
             int k=nums.size()-1;   //for 2:



             while(j<=k){
                if(nums[j]==0){
                    swap(nums[i],nums[j]);
                    i++;
                    j++;
                }
                else if(nums[j]==1){
                    j++;
                }
                else{
                    swap(nums[j],nums[k]);
                    k--;
                }
             }
    }
};
