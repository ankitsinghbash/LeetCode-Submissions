class Solution {
public:
    void nextPermutation(vector<int>& nums) {
         //first off all find the 
         int j = nums.size()-1;
         while(j>0 && nums[j-1]>=nums[j]){
            j--;
         }

         
        if(j==0){
             reverse(nums.begin(),nums.end());
        }
        else{
            //put a number at a place of j-1;
            //number is greater number from j to n;

            int k = nums.size()-1;
            for(;k>=j;k--){
                 if(nums[k]>nums[j-1]){
                    break;
                 }
            }
            swap(nums[k],nums[j-1]);


            reverse(nums.begin()+j,nums.end());
        }

    }
};


//3,2,1
