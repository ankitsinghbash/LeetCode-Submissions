#define ll long long 
class Solution {
public:
    
    bool solve(ll actual,vector<int> &time,int totalTrips){
        long long sum=0;
        for(int i=0;i<time.size();++i){
            ll value = actual/time[i];
            sum+=value;
        }
        return sum>=totalTrips;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        ll start = 1;
        ll end = (ll)*min_element(time.begin(),time.end())*totalTrips;
        while(start <=  end){
           // ll trip = 0;
            ll mid = start + (end - start)/2;
           // for(int i=0;i<time.size();i++)
             //   trip += mid / time[i];
            if(solve(mid,time,totalTrips)){
                end=mid-1;
            }
            else 
                start = mid + 1;
        }
        return start;
    }
};
