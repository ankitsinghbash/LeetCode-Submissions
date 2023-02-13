class Solution {
public:
    int countOdds(int low, int high) {
        int val = high-low;
        if(low%2!=0 && high%2!=0){
            int ans  = val/2+1;
            return ans;
        }
        else{
            if(val%2==0){
                val=val/2;
                return val;
            }
            else{
                val=val/2+1;
                return val;
            }
        }
    }
};
