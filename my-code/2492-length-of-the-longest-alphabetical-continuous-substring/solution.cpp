class Solution {
public:
    int longestContinuousSubstring(string s) {
        int cnt = 1;
        int maxx =  INT_MIN;
        if(cnt>maxx){
            maxx=cnt;
        }
    
        for(int i=1;i<s.size();i++){
           //   char ch = s.at(i);
             // char ch_back = s.at(i-1);
              int ch_idx = s[i]-'a';
              int ch_back_idx = s[i-1] - 'a';
            // cout<<ch_idx<<" ";
             // cout<<ch_back_idx<<" ";
            //  cout<<endl;
              if(ch_back_idx+1==ch_idx){
                  cnt++;
                  if(cnt>maxx){
                      maxx=cnt;
                  }
                  //cout<<"maxx"<<maxx<<endl;
              }
              else{
                  cnt=1;
              }
        }
        return maxx;
    }
};
