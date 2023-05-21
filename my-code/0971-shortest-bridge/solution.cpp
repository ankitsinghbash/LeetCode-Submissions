class Solution {
public:

    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>> &dis,queue<pair<int,pair<int,int>>> &q)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid.size() )
            return;
        if(grid[i][j]==0)
            return;

        dis[i][j]=0;
        grid[i][j]=0; 
        q.push({0,{i,j}}); // {steps till now,{x,y}}


         dfs(i+1,j,grid,dis,q);
         dfs(i,j+1,grid,dis,q); 
         dfs(i-1,j,grid,dis,q); 
         dfs(i,j-1,grid,dis,q); 
    }
    int shortestBridge(vector<vector<int>>& grid) {
        
        int n=grid.size();
        vector<vector<int>> dis(n,vector<int>(n,1e9));
        queue<pair<int,pair<int,int>>> q;
        bool flag=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {   
                    flag=1;
                    dfs(i,j,grid,dis,q);
                    break;
                }
            }
            if(flag==1) // we need to do dfs only once
                break;
        }

        int ans=1e9;
        while(!q.empty())
        {
             auto it=q.front();
           q.pop();
           int step=it.first;
           int r=it.second.first;
           int c=it.second.second;
           
           int dx[4]={-1,1,0,0};
            int dy[4]={0,0,-1,1};
           
           for(int i=0;i<4;i++)
           {
               int newr=r+dx[i];
               int newc=c+dy[i];
               
               if(newr>=0 && newc>=0 && newr<n && newc<n && dis[newr][newc]>step+1)
               {
                   if(grid[newr][newc]==1)  // if we reached '1' of another island
                   {
                       ans=min(ans,step);
                       
                   }
                   dis[newr][newc]=step+1;
                   q.push({step+1,{newr,newc}});
               }
           }
           
        }
        return ans;
        
    }
};
