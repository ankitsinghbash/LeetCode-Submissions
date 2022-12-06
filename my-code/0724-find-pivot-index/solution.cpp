class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int total_sum=0;
        for(int i=0;i<nums.size();i++){
            total_sum+=nums[i];
        }

        int sum=0;
        for(int i=0;i<nums.size();i++){
            int val = total_sum-nums[i];
            if(val%2==0){
            int half=val/2;
            if(half==sum){
                return i;
            }
            }
            sum+=nums[i];
        }
        return -1;


        
    }
};

/*
TLE:COME'S USING BRUTE FORCE:
int total=0;
        for(int i=0;i<nums.size();i++)
        {
            total+=nums[i];
        }
        
        for(int i=0;i<nums.size();i++)
        {
           //left sum;
           int leftsum=0;
           for(int j=0;j<i;j++)
           {
                leftsum+=nums[j];
           }
         
            //right sum;
            int rightsum=0;
            for(int j=i+1;j<nums.size();j++)
            {
                 rightsum+=nums[j];
            }
             
            if(leftsum==rightsum) return i;
        }
        return -1;
*/
