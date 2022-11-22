class Solution {
public:
    int minScoreTriangulation(vector<int>& arr) {
        int n=arr.size();
        //gap streagty:
        vector<vector<int>> dp(n,vector<int>(n));
        for(int g=0;g<n;g++)
        {
            for(int i=0,j=g;j<n;i++,j++)
            {
                if(g==0)
                {
                    dp[i][j]=0;
                }
                else if(g==1)
                {
                    dp[i][j]=0;
                }
                else if(g==2)
                {
                    dp[i][j]=arr[i]*arr[i+1]*arr[i+2];
                }
                else{
                    int mini=INT_MAX;
                    for(int k=i+1;k<=j-1;k++)
                    {
                        int Initial_Triangle  = arr[i]*arr[j]*arr[k];  //k is the value that make the triangle in polygon with base i and j:
                        int pleaf = dp[i][k];
                        int pright =  dp[k][j];
                        int total = Initial_Triangle+pleaf+pright;
                        mini=min(total,mini);
                    }
                    dp[i][j]=mini;
                }
            }
        }
        return dp[0][n-1];
    }
};
