class Solution {
public:
    int numberOfMatches(int n) {
        int sum=0;
        while(n>1){
            if(n%2!=0){
                n=n/2;
                sum+=n;
                n=n+1;
                 
            }
            else{
                n=n/2;
                sum+=n;
            }
        }
        return sum;
    }
};
