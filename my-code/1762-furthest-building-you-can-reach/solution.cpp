class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
         priority_queue<int,vector<int>> pq;
         int i=0;
         for(;i<heights.size()-1;i++){
              int diff = heights[i+1]-heights[i];
              if(diff<=0){
                  continue;
              }
              //You have a brick greater then as required:
              if(bricks>=diff){
                  bricks = bricks-diff;  //left brick for next jump:
                  pq.push(diff);    //Jumping possible with these of bricK , store in pq give the maximum old brick pick:
              }
              else if(ladders>0){
                     if(!pq.empty()){
                         //means in my past i use maximum brick but currently i required less number of bricks:
                         int maxx_prev = pq.top();
                         if(maxx_prev<=diff){
                             ladders--;
                         }
                         else{
                             bricks = bricks+maxx_prev;
                             pq.pop();
                             pq.push(diff);
                             bricks = bricks-diff;
                             ladders--;
                         }
                     }
                     else{
                         ladders--;
                     } 
              }
              else{
                  break;
              }
         }
         return i;
    }
};
