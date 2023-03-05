class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        //try queue in case of minimum:
        unordered_map<int,vector<int>> mp;    //store value vs index:
        for(int i=0;i<n;++i){
            mp[arr[i]].push_back(i);
        }

        vector<bool> visited(n,false);
        
        queue<int> qu;
        qu.push(0);  //push index in the queue:
        visited[0]=true;

        int step=0;
        while(!qu.empty()){
            int size = qu.size();
            while(size--){
                int curr = qu.front();
                qu.pop();
               
                if(curr==n-1){
                    return step;
                }
                
                int left = curr-1;
                int right = curr+1;
             
                if(left>0 && visited[left]==false){
                    qu.push(left);
                    visited[left]=true;
                }
                if(right<n && visited[right]==false){
                    qu.push(right);
                    visited[right]=true;
                }
                
                for(auto &idx : mp[arr[curr]]){
                    if(visited[idx]==false){
                        qu.push(idx);
                        visited[idx]=true;
                    }
                }
                mp.erase(arr[curr]);
            }
            step++;
        }
        return step;
    }
};
