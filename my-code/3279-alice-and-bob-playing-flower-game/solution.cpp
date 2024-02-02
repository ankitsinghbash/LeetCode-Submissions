class Solution {
public:
    long long flowerGame(int n, int m) {
        
        //How many odd number and how many even number in n;
         int even = n/2;
         int odd;
         if(n%2==0){
              odd = n/2;
         }
         if(n%2!=0){
              odd = n/2+1;
         }

         
    
        long long int cnt=0;
        for(int i=1;i<=m;i++){
              if(i%2==0){
                 cnt+=odd;//number of odd in n:
              }
              else{
                  cnt+=even;//number of even in n:
              }
        }
        return cnt;
    }
};
