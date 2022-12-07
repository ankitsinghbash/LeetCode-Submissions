class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

      


       vector<int> check(nums.begin(),nums.end());
       int totalzero=0;
       for(int i=0;i<nums.size();i++){
           if(check[i]==0){
               totalzero++;
               check[i]=1;
           }
       }
       int newtotal=1;
       for(int i=0;i<check.size();i++){
           newtotal*=check[i];
       }

        int prod=1;
        for(int i=0;i<nums.size();i++){
               prod*=nums[i];
        }
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(2<=totalzero){
                 ans.push_back(0);
            }
            else{
            if(nums[i]==0){
                nums[i]=1;
                int newly = newtotal/nums[i];
                ans.push_back(newly);
            }
            else
            {
                int newly = prod/nums[i];
                ans.push_back(newly);
            }
            }
        }
        return ans;
    }
};
