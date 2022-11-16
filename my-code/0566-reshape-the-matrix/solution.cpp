class Solution {
public:
  vector<vector<int>> ans;
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size();
        int m= mat[0].size();
        int given = r*c;
        int total = n*m;
        if(given==total)
        {
            vector<int> real;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    real.push_back(mat[i][j]);
                }
            }
      
        
           int k=0;
           for(int i=0;i<r;i++)
           {
               vector<int> sm;
               for(int j=0;j<c;j++)
               {
                 int val = real[k];
                 k++;
                 sm.push_back(val);
               }
               ans.push_back(sm);
           }
        return ans;

        }
        else
        {
            return mat;
        }
    }
};
