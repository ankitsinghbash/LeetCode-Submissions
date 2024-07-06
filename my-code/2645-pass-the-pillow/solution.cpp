class Solution {
public:
    int passThePillow(int n, int time) {
        if(time<n){
            return time+1;
        }
        int round = time/(n-1);
        if(round%2!=0){
            //if round is odd:
            int rest = (time)%(n-1);
            return n-rest;
        }
        else{
            int rest = (time)%(n-1);
            return rest+1;
        }
    }
};
// n = 4 time=12
// //1 2 3 4 



