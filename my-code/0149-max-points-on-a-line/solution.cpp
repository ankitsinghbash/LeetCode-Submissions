class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int maxofmax=0;
        for(int i=0;i<points.size();i++){
            unordered_map<double,int> mp;
            int samepoint=0;
            for(int j=i+1;j<points.size();j++){
                if(points[i][0]==points[j][0]&&points[i][1]==points[j][1]){
                    samepoint++;
                }
                else if(points[i][0]==points[j][0]){  //When slope is infinity:
                    mp[INT_MAX]++;
                }
                else{
                    //rest case:
                    double slope = (double)(points[j][1]-points[i][1])/(double)(points[j][0]-points[i][0]);
                    mp[slope]++;
                }
            }
           int oneextra=1;  //for 2 same slope ans number of point is 3:
            int currmax=0;
            for(auto &x : mp){
                currmax=max(currmax,x.second);
            }
            currmax+=samepoint+oneextra;
            maxofmax=max(maxofmax,currmax);
        }
        return maxofmax;
    }
};








