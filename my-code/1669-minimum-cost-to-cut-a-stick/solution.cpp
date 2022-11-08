class Solution {
	public:
      
       int fun(int i,int j,vector<int> &cuts,vector<vector<int>> &dp)
       {
           if(i>j) return 0;

           if(dp[i][j]!=-1)
           {
               return dp[i][j];
           }

           int mini=INT_MAX;
           for(int idx=i;idx<=j;idx++)
           {
               int currentcost=cuts[j+1]-cuts[i-1];
               int leftone=fun(idx+1,j,cuts,dp);
               int rightone=fun(i,idx-1,cuts,dp);
               int total=currentcost+leftone+rightone;
               mini=min(mini,total);
           }
           return dp[i][j]=mini;
       }
	

		int minCost(int n, vector<int>& cuts) {
            //add for find the length of rod: 
			cuts.insert(cuts.begin(),0);  
			cuts.insert(cuts.end(),n);

			sort(cuts.begin(),cuts.end());
			int m=cuts.size();
			vector<vector<int>> dp(m+1,vector<int>(m+1,-1));
			return fun(1,cuts.size()-2,cuts,dp);
		}
	};







/*TLE applied memo above:
 int fun(int i,int j,vector<int> &cuts)
    {
        if(i>j) return 0;
         
        int mini=INT_MAX;
        for(int idx=i;idx<=j;idx++)
        {
            int currentcost = cuts[j+1]-cuts[i-1];
            int leftone = fun(i,idx-1,cuts);
            int rightone = fun(idx+1,j,cuts);
            int total=currentcost+leftone+rightone;
            mini=min(mini,total);
        }
        return mini;
    }

    int minCost(int n, vector<int>& cuts) {
        //this is for the so we give the actual lenght directly:
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);

        sort(cuts.begin(),cuts.end());  //so that so overloading happen:
        int ans=fun(1,cuts.size()-2,cuts); //i==1 and j==cuts.size()-2;
        return ans;
        
    }


*/


