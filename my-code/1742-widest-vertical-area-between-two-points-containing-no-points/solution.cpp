class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int x1 = points[0][0];
        int maxx=0;
        for(int i=1;i<points.size();i++){
            int x2 = points[i][0];
            int width = abs(x2-x1);
            maxx = max(maxx,width);
            x1=points[i][0];
        }
        return maxx;
    }
};
