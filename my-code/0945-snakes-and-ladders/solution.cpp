class Solution {
public:


   pair<int,int> getcoodinate(int data,int n){
       int RT = (data-1)/n;  //Rt->row form top  //desi formula of row position from top;
       int RD  = (n-1)-RT;  //RD->row form down;

       //desi formula for col position:
       int col = (data-1)%n;
       if((n%2 == 1&&RD%2 == 1)||(n%2 == 0 && RD%2 == 0)){
           col = (n-1)-col;
       }
       return make_pair(RD,col);
   }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        queue<int> q;
        vector<vector<bool>> visited(n,vector<bool>(n,false));

        visited[n-1][0]=true;
        q.push(1);
       
        int step=0;
        while(!q.empty()){

            int N = q.size();
            while(N--){
               int x = q.front();
               q.pop();

               if(x==n*n){
                   return step;
               }
   
               for(int k=1;k<=6;k++){
                    int val = x+k;

                    if(val>n*n){
                        break;
                    }
                    pair<int,int> coodinate = getcoodinate(val,n);
                    int r = coodinate.first;
                    int c = coodinate.second;

                    if(visited[r][c]==true){
                        continue;
                    }
                    visited[r][c]=true;

                    if(board[r][c]==-1){
                        q.push(val);
                    }
                    else{
                        q.push(board[r][c]);
                    }
               }

            }
            step++;
        }
        return -1;
        
    }
};
