class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //threee case happen where:
        //case1 : [1,3],[2,6],[5,9],[7,8],[10,11]   //this is overlap case:
         //case2: [1,3],[4,6] //on conflicts case:
         //case3: [1,6],[2,3] //also overlap case and neglect the case of overall overlaps:


         vector<vector<int>> ans;
         sort(intervals.begin(),intervals.end());

         int i=1;
         vector<int> prev = intervals[0];

         while(i<intervals.size()){
             int starttime  = intervals[i][0];
             int endtime = intervals[i][1];
         
             int prevendtime = prev[1];

             if(prevendtime>=endtime){
                     //case overlap inside:
                     i++;
             } 
             else if(prevendtime<starttime){
                            //no conflict caes: 
                            ans.push_back(prev);
                            prev = intervals[i];
                            i++; 
             }
             else{
                    //1----3 
                    //   2---5:
                    prev[1] = endtime;
                    i++;

             }



         }
         ans.push_back(prev);
         
        
        return ans;



    }
};
