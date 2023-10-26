class Solution {
public:
   int solve(int n,int k){
   
     if(n==1 && k==1){
         return 0;
     }

    int total = 1<<n-1;  //2^power(n-1) is binary form:
    int mid = total/2;
    if(k<=mid){
        return solve(n-1,k);
    }
    else{
        return 1-solve(n-1,k-mid);
    }
  
   }

    int kthGrammar(int n, int k) {
        return solve(n,k);
    }
};
