class Solution {
public:
    
      static bool cmp(vector<int> &a,vector<int> &b){
       return a[0]<b[0];
      }
    
    int countDays(int days, vector<vector<int>>& meetings) {
       
        
        
        vector<vector<int>> intervals(meetings.begin(),meetings.end());
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
      
  
        
        
        //This logic work for if no meeting overlap:
        
        int meeting_happen = 0;  //total number of day meeting happen:
        for(int  i=0;i<store.size();i++){
            int start = store[i][0];//starting day of meeting:
            int end = store[i][1];  //it show the end day of meeting:
            meeting_happen+=end-start+1;           
        }
        return (days-meeting_happen);
        
        
        
        
        
        //[1,3],[1,5]  //here meeting may overlaps:
        
        
        //first of all bluild our logic::
        
 
        //[1,3],[1,5]     //suppose there are 7 day:  output was : 2 day where worker are present but no meeting happen:
        //[1,5]:
        
        
        
        //fisrt is brute force:
       // and second was a binary search method:
        
    }
};
