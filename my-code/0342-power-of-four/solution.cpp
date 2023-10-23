class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0){
            return false;
        }

        while(n>=4){
            int rem = n%4;
            if(rem!=0){
                return false;
            }
            n = n/4;
        }
        if(n==1){
            return true;
        }
        return false;
    }
};
