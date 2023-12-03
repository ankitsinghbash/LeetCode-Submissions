class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans=0;
        for(int i=1;i<points.size();i++){
            int prev_x = points[i-1][0];
            int prev_y = points[i-1][1];

            int curr_x = points[i][0];
            int curr_y = points[i][1];
   
            int dx = abs(curr_x - prev_x);
            int dy = abs(curr_y - prev_y);
            
            ans+=min(dx,dy)+abs(dy-dx);
        }
        return ans;
    }
};
