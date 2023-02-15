class Solution {
public:
    vector<int> addToArrayForm(vector<int>& nums, int k) {
         int j=nums.size()-1;
         int carry=0;
         vector<int> ans;
         while(j>=0){
             int sum = nums[j]+k%10+carry;
             int rem = sum%10;
             ans.insert(ans.begin(),rem);
             carry=sum/10;
             k=k/10;
             j--;
         }

         while(k>0){
             int sum = k%10+carry;
             int rem = sum%10;
             ans.insert(ans.begin(),rem);
             carry=sum/10;
             k=k/10;
         }
         if(carry>0){
             ans.insert(ans.begin(),carry);
         }
         return ans;


    }
};
