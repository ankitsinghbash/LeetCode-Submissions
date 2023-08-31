class Solution {
public:

   static bool cmp(vector<int> &a,vector<int> &b){

     return a[0]<b[0];
   }



    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //mst question hai"
        int cnt=0;
        int i=1;
        sort(intervals.begin(),intervals.end(),cmp);
        vector<int> prev = intervals[0];
        int n = intervals.size();
        while(i<n){
            vector<int> curr = intervals[i];
            int currstart = curr[0];
            int currend = curr[1];

            int prevend = prev[1];


            if(prevend<=currstart){
                prev = curr;
                i++;

            }
            else{
                 if(prevend>currend){
                     prev = curr;
                     cnt++;
                     i++;
    
                 }
                 else{

                       i++;
                       cnt++;
                 }

            }
        }

           return cnt;







    }
};
