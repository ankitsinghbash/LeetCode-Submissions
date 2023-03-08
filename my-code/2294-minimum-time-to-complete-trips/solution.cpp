#define ll long long 
class Solution {
public:
    
    ll solve(ll actual,vector<int> &time){
        long long sum=0;
        for(int i=0;i<time.size();++i){
            ll value = actual/time[i];
            sum+=value;
        }
        return sum;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        ll start = 1;
        ll end = (ll)*min_element(time.begin(),time.end())*totalTrips;
        while(start <= end){
            ll mid = start + (end - start)/2;
            if(solve(mid,time)<totalTrips){
                start=mid+1;
            }
            else 
                end=mid-1;
        }
        return start;
    }
};
