class Solution {
public:

   int solve(vector<int> &nums,int n,int val,vector<bool> &visited,unordered_map<vector<bool>,int> &mp){


    if(mp.find(visited)!=mp.end()){
        return mp[visited];  //mp[visited]-->define score as in second value:
    }
    
    int maxx_score = 0;
     for(int i=0;i<n-1;i++){
         if(visited[i]==true) continue;
         for(int j=i+1;j<n;j++){ 
             if(visited[j]==true) continue;
             visited[i]=true;
             visited[j]=true;
             int total = val*__gcd(nums[i],nums[j]);
             int rest = solve(nums,n,val+1,visited,mp);  //Notice here next time ke lyia koi index increment nahi hai basically hum visited ko asa send kar rahe hai ki next time true pe jaay: call tab tak hogi jab taak i==n-1 nahi ho jaay:
             visited[i]=false;  //backtrack: 
             visited[j]=false;
             maxx_score = max(maxx_score,total+rest); 
         }
     } 
     return mp[visited] = maxx_score;   //store score in the map value:
   }



    int maxScore(vector<int>& nums) {
        int n = nums.size();

        unordered_map<vector<bool>,int> mp;
        vector<bool> visited(nums.size(),false);
        return solve(nums,n,1,visited,mp);  //In memo visited and val change: Time complexity: O(N^2)*(2^N)*log(M):
    }
};
