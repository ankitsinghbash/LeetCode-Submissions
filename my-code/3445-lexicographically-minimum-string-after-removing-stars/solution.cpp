class Solution {
public:
    typedef pair<char,int> p;
    //always remmber in pq top in b and below it is a now apply similar logic:
    struct cmp{
        bool operator()(const pair<char,int> &a,const pair<char,int> &b){

           
              if(a.first==b.first){
                 return b.second>a.second;
              }

              return a.first>b.first;


        }
    };
    

    string clearStars(string s) {
           //priority_queue problem:
           priority_queue<p,vector<p>,cmp> pq;  //min heap:
           
           for(int i=0;i<s.size();i++){
                if(s[i]=='*'){
                     if(!pq.empty()){
                        pair<char,int> P = pq.top();
                        pq.pop();
                        char ch = P.first;
                        int idx = P.second;
                        s[idx] = '#';
                        s[i] = '#';
                     }
                }
                else{
                     pq.push({s[i],i});
                }
           }



           string ans="";
           for(int i=0;i<s.size();i++){
               if(s[i]!='#'){
                  ans+=s[i];
               }
           }
           return ans;
    }
};
