class Solution {
public:

   bool check(long long n,long long val){
      if(n==1) return true;

      val=2*val;
      
      if(val==n){
          return true;
      }

      if(val>n){
          return false;
      }

      return check(n,val);
      
   }

    bool isPowerOfTwo(long long n) {
        bool ans=check(n,1);
        if(ans==true) return true;
        else return false;
    }
};
