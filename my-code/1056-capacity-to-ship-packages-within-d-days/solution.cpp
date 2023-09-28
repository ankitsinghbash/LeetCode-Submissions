class Solution {
public:
   
    int solve(int cap,vector<int> &weights){

       int curr=0;
       int cnt=0;
       for(int i=0;i<weights.size();i++){
           int val =  weights[i];
           if(val>cap){
               return INT_MAX;
           }
           curr+=val;
           if(curr==cap){
               cnt++;
               curr=0;
           }
           if(curr>cap){
               cnt++;
               curr=val;
           }
       }
       if(curr!=0){
           if(curr<=cap){
               cnt++;
           }
       }
       return cnt;



    }
  


    int shipWithinDays(vector<int>& weights, int days) {
        int low = *min_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
 
       while(low<=high){
           int cap = low+(high-low)/2;
           if(solve(cap,weights)<=days){
               high=cap-1;
           }
           else{
               low = cap+1;
           }
       }
       return low;

    }
};
