class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        //first we have to find the transpose of the matrix:
        //then we swaping the col form start of end:
        //transpose:
        int n=matrix.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++) //j=i true / not j=0; important condition of transpose:
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        //form above we find the transpose:
        //Now swap the column from start to end:
        for(int i=0;i<n;i++)  //go to every row:
        {
            int mincol=0;
            int maxcol=n-1;
            while(mincol<maxcol)
            {
                swap(matrix[i][mincol],matrix[i][maxcol]);
                mincol++;
                maxcol--;
            }
        }
        
    }
};
