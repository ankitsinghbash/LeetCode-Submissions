class Solution {
public:
   static bool cmp(vector<int> &a,vector<int> &b){
       return a[0]<b[0];
   }


    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
  
        vector<vector<int>> store;
        vector<int> prev = intervals[0];
        int i=1;
        int n = intervals.size();
        while(i<n){
            vector<int>  curr = intervals[i];

            int prevend = prev[1];
            int currstart = curr[0];
            int currend = curr[1];
            if(prevend<currstart){
                store.push_back(prev);
                prev = curr;
                i++;
            } 
            else{  //overlap:
                 prev[1] = max(prev[1],currend);
                 i++;
            }   
        }
        store.push_back(prev);
        return store;
  
        

    }
};
