class Solution {
public:
    int numWaterBottles(int bottle, int ex) {
         int ans=0;
          ans+=bottle;
            while(bottle>=ex){
                  
                   int full = bottle/ex;
                   int rest = bottle%ex;
                  
                   int total_rest = full+rest;
                   bottle = total_rest;  
                   ans+=full;

             }        
             return ans;            
         
    }
};
