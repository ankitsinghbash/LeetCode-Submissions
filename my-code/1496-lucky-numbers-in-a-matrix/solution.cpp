class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        
       vector<int> answer;
       int i=0;
       while(i<matrix.size())
       {
           //i=0,find minimum;
           int mini=INT_MAX;
           int col;
           for(int j=0;j<matrix[0].size();j++)
           {
                if(matrix[i][j]<mini)
                {
                    mini=matrix[i][j];
                    col=j;
                }
           }
           //basically mini is my smallest number in row; with j=col;
           //condition for lucky number if mini is the maximum of [i][col] then it only a lucky other wise;
           int real = mini;
           for(int i=0;i<matrix.size();i++)
           {
               if(matrix[i][col]>mini)
               {
                   mini=matrix[i][col]; //mini update:
               } 
           }
           //if real and mini is not same mean's it goto update:
           if(real==mini)   //if real or mini is same means mini<ever column value:
           {
               answer.push_back(mini);
           }
           i++;
       }
       return answer;

    }
};
