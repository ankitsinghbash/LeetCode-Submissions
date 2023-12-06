class Solution {
public:
    int totalMoney(int n) {
        //O(N):
        int time = n/7;
        int last = n%7;
        int start = time+1;

        int lastans=0;
        while(last--){
            lastans+=start;
            start++;
        }

     int timeans=0;
     int cnt=0;
     int day = 7;
     while(time--){
         int val = day*(day+1)/2-cnt*(cnt+1)/2;;
         timeans+=val;
         day++;
         cnt++;
        
     }
     return timeans+lastans;
    }
};
