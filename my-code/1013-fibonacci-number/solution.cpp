class Solution {
public:
   int solve(int n){
       if(n==0 || n==1){
           return n;
       }

       int value = solve(n-1)+solve(n-2);
       return value;
   }
 



    int fib(int n) {
        return solve(n);
    }
};
