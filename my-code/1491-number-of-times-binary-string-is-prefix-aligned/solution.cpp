class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        flips.insert(flips.begin(),0);
        int maxx = flips[1];
        int cnt = 0;
        for(int i=1;i<flips.size();i++){
             maxx=max(maxx,flips[i]);
             if(i==maxx){
                 cnt++;
             }
        }
        return cnt;
    }
};
