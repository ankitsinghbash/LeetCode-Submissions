class Solution {
public:

    vector<vector<int>> make_a_matrix(int n)
    {
        int minrow=0;
        int maxrow=n-1;
        int mincol=0;
        int maxcol=n-1;
        vector<int> ans;
        int total=n*n;
        int counter=0;
        vector<vector<int>>  matrix(n,vector<int>(n));
        int k=1;
        while(counter!=total)
        {
          for(int i=mincol;i<=maxcol&&counter!=total;i++)
          {
            matrix[minrow][i]=k;
            k++;
            counter++;
          }
          minrow++;
          for(int i=minrow;i<=maxrow&&counter!=total;i++)
          {
              matrix[i][maxcol]=k;
              k++;
              counter++;
          }
          maxcol--;
          
          for(int i=maxcol;i>=mincol&&counter!=total;i--)
          {
              matrix[maxrow][i]=k;
              k++;
              counter++;
          }
          maxrow--;
          
          for(int i=maxrow;i>=minrow&&counter!=total;i--)
          {
              matrix[i][mincol]=k;
              k++;
              counter++;
          }
          mincol++;
        }
        return matrix;
    }


    vector<vector<int>> generateMatrix(int n) {
       vector<vector<int>> matrix =  make_a_matrix(n);
       //Know applied the logic of spiral traversal;
       return matrix;
    }
};
