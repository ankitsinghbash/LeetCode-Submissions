class Solution {
public:
    int dp[501][501];
    int solve(int i,int j,vector<int> &nums1,vector<int> &nums2){
     if(i>=nums1.size() || j>=nums2.size()){
         return -1001;
     }

     if(dp[i][j]!=-1){
         return dp[i][j]; 
     }


     int first = nums1[i]*nums2[j]+solve(i+1,j+1,nums1,nums2);
     int second = solve(i+1,j,nums1,nums2);
     int third = solve(i,j+1,nums1,nums2);
     int fourth = solve(i+1,j+1,nums1,nums2);
     int five = nums1[i]*nums2[j];

     return dp[i][j] = max({first,second,third,fourth,five});


    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,nums1,nums2);
    }
};
