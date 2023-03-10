class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        //using bfs:
        int n = arr.size();
        queue<int> qu;
        vector<bool> visited(n,false);
        
        qu.push(start);
        visited[start]=true;

        while(!qu.empty()){
           int size = qu.size();
           while(size--){           //this while is mentadory because every time we add only one value in queue:
           int curr_idx  = qu.front();
           qu.pop();
           if(arr[curr_idx]==0) return true;

           int left =  curr_idx-arr[curr_idx];
           if(left>=0 && visited[left]==false){
               qu.push(left);
               visited[left]=true;
           }
           int right = curr_idx+arr[curr_idx];
           if(right<n && visited[right]==false){
               qu.push(right);
               visited[right]=true;
           }
           }
        }
        return false;
    }
};

//Depth first search:
/*
class Solution {
public:
    //visited is required to check loop is not present example-> {3,0,2,1,2};
   bool dfs(vector<int> &arr,int start,int n,vector<bool> visited){
      
      if(start<0 || start>=n || visited[start]==true) return false;
      
      if(arr[start]==0) return true;
      
      visited[start]=true;
  
      return  dfs(arr,start+arr[start],n,visited) || dfs(arr,start-arr[start],n,visited);
   }


    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n,false);
        return dfs(arr,start,n,visited);
    }
*/


