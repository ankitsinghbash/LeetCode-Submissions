/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    typedef long long ll;
    int guessNumber(int n) {
        int low=1;
        int high = n;
        int val = guess(low);
        if(val==0) return low;
        int val1 = guess(high);
        if(val1==0) return high;
        
        while(low<high){
            int mid = low+(high-low)/2+1;
            int val = guess(mid);
            if(val==0){
                return mid;
            }
            if(val==1){
                 low=mid;
            }
            else{
                 high=mid-1;
            }
        }
        return -1;
    }
   
    
};
