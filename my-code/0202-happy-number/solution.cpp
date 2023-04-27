class Solution {
public:
   
   long long check(int n){
       long long sum=0;
       while(n!=0){
           int rem = n%10;
           int val =  pow(rem,2);
           sum+=val;
           n=n/10;
       }
      return sum;
   }

    unordered_set<int> s;
    bool isHappy(int n) {
        while(n!=1){
             int valueoptain = check(n);
             if(s.find(valueoptain)!=s.end()){
                 return false;
             }
             s.insert(valueoptain);
             n=valueoptain;
        }
        return true;
    }
};
