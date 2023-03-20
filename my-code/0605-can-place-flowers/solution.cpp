class Solution {
public:

    bool canPlaceFlowers(vector<int>& arr, int n) {
        vector<int> store;
        for(int i=0;i<arr.size();++i){
            if(arr[i]==0){
                store.push_back(i);
            }
         }
        
        vector<bool> visited(arr.size(),false);

        for(int i=0;i<store.size();i++){
            int idx  = store[i];
            if(visited[idx]==false){
                
                int left = max(idx-1,0);
                int k = arr.size()-1;
                int right = min(idx+1,k);   //never use any funtion inside the max(),min() ex->max(1,ans,size());  //got error:
                if(arr[left]==0 && arr[right]==0){
                    n--;
                    visited[idx]=true;
                    visited[left]=true;
                    visited[right]=true;
                }
            }
        }
        if(n<=0){
            return true;
        }
        return false;
    }
};
