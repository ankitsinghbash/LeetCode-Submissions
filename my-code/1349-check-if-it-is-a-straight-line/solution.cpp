class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {

        for(int i=2;i<coordinates.size();i++){
            //new slope:
            int x = coordinates[i-2][0];
            int y = coordinates[i-2][1];

            int x1 = coordinates[i-1][0];
            int y1 = coordinates[i-1][1];
     
            int x2 = coordinates[i][0];
            int y2 = coordinates[i][1];

            if((x1-x)*(y2-y1)!=(x2-x1)*(y1-y)){
                return false;
            }
        }
        return true;

    }
};
