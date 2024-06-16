class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int j=nums.size()-1;
        while(j>0 && nums[j-1]>=nums[j]){
            j--;
        }
       
        
        if(j==0){
            reverse(nums.begin(),nums.end());
            return;
        }

        int mini = INT_MAX;
        int idx=0;
        for(int i=j;i<nums.size();i++){
            if(nums[i]>nums[j-1]){
                    if(nums[i]<=mini){
                        mini =nums[i];
                        idx = i;
                    }
            }
        }

       
        swap(nums[j-1],nums[idx]);      


        reverse(nums.begin()+j,nums.end());
       

    } 
};



//[23,1,3,3,12]



