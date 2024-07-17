class Solution {
public:
    typedef long long ll;
    long long  minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(horizontalCut.begin(),horizontalCut.end(),greater<int>());
        sort(verticalCut.begin(),verticalCut.end(),greater<int>());
        ll row = 1;
        ll col = 1;
        
        ll i=0;
        ll j=0;
        ll total_cost = 0;
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
