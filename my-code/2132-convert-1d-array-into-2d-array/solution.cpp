class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> construct2DArray(vector<int>& original, int n, int m) {
         int boxsize = original.size();
         int total = n*m;
         if(total==boxsize)
         {
             //change
             int k=0;
             for(int i=0;i<n;i++)
             {
                 vector<int> sm;
                 for(int j=0;j<m;j++)
                 {
                    int val = original[k];
                    k++;
                    sm.push_back(val);
                 }
                 ans.push_back(sm);
             }
             return ans;
         }
         else
         {
             return {};
         }


    }
};
