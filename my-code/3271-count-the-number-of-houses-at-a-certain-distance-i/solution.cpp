class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        unordered_map<int,vector<int>> mp;
        for(int i=1;i<n;i++){
            mp[i].push_back(i+1);
            mp[i+1].push_back(i);
        }
        
        mp[x].push_back(y);
        mp[y].push_back(x);
        
       
        vector<int> ans(n,0);
         //Now find the path which is minimum and distance is equal to k means cnt from k=1 to n
        for(int i=1;i<=n;i++){
            vector<int> distance(n+1,-1);
            queue<int> qu;
            qu.push(i);
            distance[i]=0;
            while(!qu.empty()){
                int current = qu.front();
                qu.pop();
                for(auto x : mp[current]){
                    if(distance[x]==-1){
                        distance[x]=distance[current]+1;
                        qu.push(x);
                    }
                }
            }
            
            for(int k=1;k<=n;k++){
                if(i==k) continue;
                int alpha = distance[k];
                if(alpha!=-1){
                    ans[alpha-1]++;
                }
            }
        }
        return ans;
    }
};
