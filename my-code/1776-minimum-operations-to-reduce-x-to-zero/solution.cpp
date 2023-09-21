class Solution {
public:
    //optimal solution:
    int minOperations(vector<int>& nums, int x) {
        //{left,sum-x,right}
        //approach we have to find the longest sub-array have sum-x value 
        //answer is nums.size()-longest_subarry(have sum (sum-x)):
        int sum=0;
        sum = accumulate(nums.begin(),nums.end(),0);
       

        if(sum<x) return -1;
        int subarray = sum-x;


        //NOw find the longest subarray have sum equal to subarray value in nums:
    
        int maxx = INT_MIN;
        int left=0;
        int n = nums.size();
        int curr=0;
        for(int right=0;right<nums.size();right++){
            curr+=nums[right];
            while(left<nums.size() && curr>subarray){
                curr-=nums[left];
                left++;
            }
            if(curr == subarray){
                maxx = max(maxx,right-left+1);
            }
        }
        return maxx==INT_MIN ? -1 : nums.size()-maxx;
    }
};

//tle solution:
// class Solution {
// public:
//     int mini = INT_MAX;
//     void solve(int i,int j,vector<int> &nums,int x ,int cnt,vector<vector<vector<int>>> &dp){
//          if(x==0){
//             mini = min(mini,cnt);
//             return;
//         }

//         if(x<0 || i>j){
//             return;
//         }
//         if(dp[i][j][x]!=-1){
//             return;
//         }
       
//          solve(i+1,j,nums,x-nums[i],cnt+1,dp);
//          solve(i,j-1,nums,x-nums[j],cnt+1,dp);

//          dp[i][j][x] = mini;  //technique to memo in the void function:

//     }


//     int minOperations(vector<int>& nums, int x) {
//         int n = nums.size();
//         vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(x+1,-1)));
//         solve(0,nums.size()-1,nums,x,0,dp);
//         return mini==INT_MAX ? -1 : mini;
//     }
// };
