class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(horizontalCut.begin(),horizontalCut.end(),greater<int>());
        sort(verticalCut.begin(),verticalCut.end(),greater<int>());
        int row = 1;
        int col = 1;
        
        int i=0;
        int j=0;
        int total_cost = 0;
        while(i<=m-2 && j<=n-2){
             if(horizontalCut[i]>verticalCut[j]){
                 total_cost+=horizontalCut[i]*col;
                 row++;
                 i++;
             }
            else{
                //verticalCut is more:
                total_cost+=verticalCut[j]*row;
                col++;
                j++;
            }
        }
        
        
        while(i<=m-2){
            total_cost+=horizontalCut[i]*col;
            row++;
            i++;
        }
        
        while(j<=n-2){
            total_cost+=verticalCut[j]*row;
            col++;
            j++;
        }
        
        return total_cost;
        
        
        
    }
};
