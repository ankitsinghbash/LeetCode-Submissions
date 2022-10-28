class Solution 
{ public:
 int distanceBetweenBusStops(vector<int> &distance, int start, int destination) 
 {
      int dist1, dist2, sum = 0;
//we will start iterating from start position 
int j = start; 
  int size = distance.size(); 
  /*iterate completely from start to start to cover both the distances 1) start -> destination 2) destination -> start */
   while (size)
    { 
        sum += distance[j];
         j++; 
         if (j == distance.size()) 
         j = 0; 
    //destination reached from start - store the result //now calculate distance from destination to start
     if (j == destination)
      { 
          dist1 = sum; 
          sum = 0;
     } 
     size--; 
     } //storing result from destination to  start 
     dist2 = sum;
      return min(dist1, dist2);
       }
        };
