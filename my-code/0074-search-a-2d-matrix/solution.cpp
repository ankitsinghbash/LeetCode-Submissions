class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        //Best solution Gfg same questin me hai:
        // O(N);
        
         int i=0;
         int maxcol=matrix[0].size()-1;
         int maxrow=matrix.size()-1;
          
         int j=maxcol;
	     while(i>=0 && i<=maxrow &&j>=0 && j<=maxcol)
	     {
	         if(matrix[i][j]==target) return true;
	         else if(matrix[i][j]>target) j--;
	         else i++;
	     }
        return false;
        
        
        //
        
        /* This is o(n*2);
        int minrow=0;
        int maxrow=matrix.size()-1;
        int mincol=0;
        int maxcol=matrix[0].size()-1;
        
        for(int i=minrow;i<=maxrow;i++)
        {
            for(int j=mincol;j<=maxcol;j++)
            {
                if(matrix[i][j]==target)
                {
                    return true;
                }
            }
        }
        return false;
        */
        //O(n);
        //left and right is define for the coloumn:
        /*
        int left=0;
        int right=matrix[0].size()-1;
        
        int maxrow=matrix.size()-1;
        
        for(int i=0;i<=maxrow;i++)
        {
            if(target>matrix[i][right])
            {
                continue;
            }
            
            //now here element if find by the left of binary search:
             while(left<=right){
                int mid=(left+right)/2;
                if(matrix[i][mid]==target) return true;
                if(matrix[i][mid]>target){
                    right=mid-1;
                }else if(matrix[i][mid]<target){
                    left=mid+1;
                }
            }
            return false;
        }
        return false;
        */
    }
};
