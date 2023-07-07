class Solution {
public:
   //'F'-->'T'
   void solve(int &maxx,string answerKey,int k){
    int start =0;
    int j=0;
    int n = answerKey.size();
    int cnt=0;
    while(j<n){
          if(answerKey[j]=='F'){
              cnt++;
              if(cnt>k){
                 int size = j-start;
                  maxx = max(maxx,size);
                  cnt=cnt-1;
                  while(answerKey[start]!='F'){
                      start++;
                  }
                  start=start+1;
              }
          }
          j++;
    }
    maxx = max(maxx,n-start);
    
   }

   //'T'-->'F'
   void solve1(int &maxx1,string answerKey,int k){
    int start =0;
    int j=0;
    int n = answerKey.size();
    int cnt=0;
    while(j<n){
          if(answerKey[j]=='T'){
              cnt++;
              if(cnt>k){
                 int size = j-start;
                  maxx1 = max(maxx1,size);
                  cnt=cnt-1;
                  while(answerKey[start]!='T'){
                      start++;
                  }
                  start=start+1;
              }
          }
          j++;
    }
    maxx1 = max(maxx1,n-start);
   }




    int maxConsecutiveAnswers(string answerKey, int k) {
        int maxx=0;
        int maxx1=0;
        solve(maxx,answerKey,k);
        solve1(maxx1,answerKey,k);
        return max(maxx,maxx1);
    }
};
