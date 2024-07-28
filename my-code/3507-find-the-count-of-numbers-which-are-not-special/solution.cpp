class Solution {
public:
    int nonSpecialCount(int l, int r) {
            int n = sqrt(r);
            vector<int> box(n+1,false);
        
        
         
          
           box[0]=true;
           box[1]=true;  // true means prime:
           int cnt=0;
           vector<int> prime;
           for(int i=2;i<=n;i++){
               if(box[i]==false){
                   prime.push_back(i);
                   for(int j = i*i;j<=n;j+=i){
                         box[j] = true;
                   }
               }
           }
        
        
        //I not put 1 in box , 1 is also prime but not put in prime vector:
         for(int i=0;i<prime.size();i++){
               int value = prime[i]*prime[i];
             if(value>=l && value<=r){
                 cnt++;    //for special number cnt:
             }
         }
          
        //1 is not a special number that why not but in prime vector to check it is lie in the range of l && r:
          int total  = r-l+1;
          int ans = total-cnt;
          return ans;
        
    }
};
