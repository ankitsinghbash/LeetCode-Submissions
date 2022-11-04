class Solution {
public:

    int recursion(int i,int j,vector<vector<int>> &grid)
    {
        if(i<0||j<0||i==grid.size()||j==grid[0].size()||grid[i][j]==0)
            return 0;

        int temp=grid[i][j];
        grid[i][j]=0;  //ki visited mat karo aab:
        int ans=temp;   //take a varible to add the all answer:
        int ans1=0;
        ans1=max(ans1,recursion(i+1,j,grid));
        ans1=max(ans1,recursion(i,j+1,grid));
        ans1=max(ans1,recursion(i-1,j,grid));
        ans1=max(ans1,recursion(i,j-1,grid));
        ans+=ans1;
        grid[i][j]=temp;  //make grid again visited:
        return ans;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                ans = max(ans,recursion(i,j,grid));
            }
        }
        return ans;
    }
};
