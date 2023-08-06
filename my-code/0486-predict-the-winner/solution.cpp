class Solution {
public:
   int solve(int i,int j,vector<int> &nums,bool chance,int myans){
     
      if(i>j){
          return 0;
      }
    
      if(chance==true){
          myans+=max(nums[i]+solve(i+1,j,nums,false,myans),nums[j]+solve(i,j-1,nums,false,myans));     
      }
      else{
           myans+=min(-nums[i]+solve(i+1,j,nums,true,myans),-nums[j]+solve(i,j-1,nums,true,myans)); 
      }
      return myans;
   }




    bool predictTheWinner(vector<int>& nums) {
        int myans=0;
        int j = nums.size()-1;
        return solve(0,j,nums,true,myans)>=0;

      // if(myans>=0) return true; //never use this because there is no & referece in our answer:
        //if i pass reference then backtrack not happen: check both solution: 
       // return false;
    }
  
};
