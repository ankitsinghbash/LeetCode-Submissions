class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n,false);
        queue<int> qu;
        qu.push(0);
        visited[0]=true;
        while(!qu.empty())
        {
            int current = qu.front();                                                                                                                 
            qu.pop();
 
            for(auto x : rooms[current]){
                if(visited[x]==false)
                {
                  qu.push(x);
                  visited[x]=true;
                }

            }
        }


       for(int i=0;i<n;i++){
           if(visited[i]==false){
               return false;
           }
       }
       return true;

    }
};
