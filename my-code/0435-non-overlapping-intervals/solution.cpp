class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int cnt=0;
        int i=1;
        vector<int> prev = intervals[0];
        int n = intervals.size();
        while(i<n){
           vector<int> curr = intervals[i];
           
           int prevend = prev[1];
           int currstart = curr[0];
           int currend = curr[1];
           if(prevend<=currstart){ //non overlapping:
               prev = curr;
               i++;
           }
           else{
               if(prevend>currend){
                   prev = curr;
                   i++;
                   cnt++;
               }
               else{
                   i++;
                   cnt++;
               }
           }


        }
        return cnt;


        return cnt;
    }
};
