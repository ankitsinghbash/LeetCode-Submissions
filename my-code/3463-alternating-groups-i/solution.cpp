class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        //check for each element left and right with alternative color:
        int ans=0;
        int n = colors.size();
        for(int i=0;i<colors.size();i++){
               int current = colors[i];
               if(current==0){
                    int next = (i+1)%n;
                    int idx = (i-1);
                    if(idx<0){
                        idx = n+idx;
                    }
                   int prev = (idx%n);
                   if(colors[prev]==1 && colors[next]==1){
                       ans++;
                   }
               }
            else if(current==1){
                  int next = (i+1)%n;
                    int idx = (i-1);
                    if(idx<0){
                        idx = n+idx;
                    }
                   int prev = (idx%n);
                   if(colors[prev]==0 && colors[next]==0){
                       ans++;
                   }
            }
        }
        return ans;
    }
};
