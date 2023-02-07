class Solution {
public:
    int totalFruit(vector<int>& arr) {
        vector<int> ans;
        vector<int> cnt;
        int counter=1;
        for(int i=1;i<arr.size();i++){
            if(arr[i]==arr[i-1]){
                counter++;
            }
             if(arr[i]!=arr[i-1]){
                 ans.push_back(arr[i-1]);
                 cnt.push_back(counter);
                 counter=1;
             }
        }
        ans.push_back(arr[arr.size()-1]);
        cnt.push_back(counter);

       if(ans.size()<=1){
           return cnt[0];
       }
 
        //initial cost;
        int initial_cost=0;
        int maxx=0;
        for(int i=0;i<2;i++){
              initial_cost+=cnt[i];
        }
        maxx=max(maxx,initial_cost);
        cout<<maxx<<endl;
        for(int i=2;i<ans.size();i++){
            if(ans[i]==ans[i-1] || ans[i]==ans[i-2]){
                initial_cost+=cnt[i];
            }
            else{
                initial_cost=0;
                initial_cost+=cnt[i-1];
                initial_cost+=cnt[i];
            }
            maxx=max(maxx,initial_cost);
        }
        return maxx;
        
    }
};
