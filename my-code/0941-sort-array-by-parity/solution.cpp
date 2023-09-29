class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
       int i=0;
       int j=nums.size()-1;
       while(i<=j){
           if(nums[i]%2==0 && nums[j]%2!=0){ //even then odd:
                   i++;
                   j--;
           }
           else if(nums[i]%2==0 && nums[j]%2==0){ //even then even
               i++;
           }
           else if(nums[i]%2!=0 && nums[j]%2==0){  //odd then even
               swap(nums[i],nums[j]);
               i++;
               j--;
           }
           else{     //odd then odd:
               j--;
           }
       }
 



        return nums;
    }
};
