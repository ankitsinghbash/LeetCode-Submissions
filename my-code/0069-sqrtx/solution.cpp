class Solution {
public:
    typedef long long ll;
    int mySqrt(int x) {
        if(x==0 || x==1) return x;
        ll low  =1;
        ll high =x;
        int result = -1;
        while(low<high){
            ll mid = low+(high-low)/2;
            ll val = mid*mid;
            if(x==val){
                return mid;
            }
            else if(mid*mid<x){
                result =  mid;
                low = mid+1;
            }
            else{
                high = mid;
            }
        }
        return result;
    }
};
