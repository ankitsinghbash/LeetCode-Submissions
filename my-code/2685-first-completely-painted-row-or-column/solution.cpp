class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> rowid(n*m+1);
        vector<int> colid(n*m+1);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int val = mat[i][j];
                rowid[val]=i;
                colid[val]=j;
            }
        }
        
        vector<int> rowans(n,0);
        vector<int> colans(m,0);
        
        for(int i=0;i<arr.size();i++){
            
            int x =  arr[i];
            
            int idx =  rowid[x];
            int idc = colid[x];
            
            rowans[idx]++;
            colans[idc]++;
            
            
           // [1,4,5,2,6,3]
          //[[4,3,5],[1,2,6]]
            
            if(rowans[idx]==m || colans[idc]==n){  //row equal to col and col equal to row test above give test case:           
                return i;
            }
        }
        return -1;
        
        
        
    }
};
