class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
         int n = customers.size();
    
         int current_time = 0;
         double w=0.0;
          for(int i=0;i<customers.size();i++){
               int start = customers[i][0];
               int time = customers[i][1];
            
               if(start<current_time){
                              w += current_time-start+time;
                             
               }
               else if(start>=current_time){
                   w+=time;
                   current_time = start;
               }
               current_time = current_time+time;

          }

   
          return w*1.0/n;
 
              
    }
};


//   1-------3
//        2-----------------------------
