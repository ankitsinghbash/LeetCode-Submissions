class Solution {
public:
    int maxProfitAssignment(vector<int>& diff, vector<int>& profit, vector<int>& worker) {

         int n = worker.size();
         int m = diff.size();

        vector<pair<int,int>> store;
        for(int i=0;i<m;i++){
              store.push_back({diff[i],profit[i]});
        }
        sort(diff.begin(),diff.end());
        sort(store.begin(),store.end());


        
         int ans=0;
         for(int i=0;i<n;i++){
             int value = worker[i];
              
            //apply binary search:
            //from 0 to kth index where value is just greater then:
            int k=-1;
            int low = 0;
            int high = m-1;
            if(store[high].first<=value){
                k = high;
            }
            while(low<high){
                int mid = (low+high+1)/2;
                if(store[mid].first<=value){
                       low = mid;
                       k = mid;
                }
                else{
                      high = mid-1;
                }
            }

            if(k==-1 && store[low].first<=value){
                k = low;
            }





            int maxx=0;
            for(int i=0;i<=k;i++){
                maxx = max(maxx,store[i].second);
            }
             ans+=maxx;
         }
         return ans;
    }
};
