class Solution {
public:
   int solve(int i,int j,vector<int> &nums){
       if(j<i){
           return 0;
       }


       int taken = nums[i] + min(solve(i+2,j,nums),solve(i+1,j-1,nums));
       int secondtaken = nums[j] + min(solve(i+1,j-1,nums),solve(i,j-2,nums));

       return max(taken,secondtaken);

   }
 
    bool predictTheWinner(vector<int>& nums) {
        //If both play optimal the player it's own turn taken maximum and player2 give
        int total=0;
        total = accumulate(nums.begin(),nums.end(),0);
        int player1 = solve(0,nums.size()-1,nums);
        int player2 = total-player1;
        return player1>=player2;
    }
};
