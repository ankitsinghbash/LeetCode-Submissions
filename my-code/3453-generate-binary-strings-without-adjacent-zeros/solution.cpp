class Solution {
public:
    vector<string> ans;
    void solve(int n,string st,char prev){
        if(n==0){
            ans.push_back(st);
            return;
        }
        
        if(prev=='\0' || prev!='0'){
         solve(n-1,st+'0','0');
        }
         solve(n-1,st+'1','1');
    }
    
    vector<string> validStrings(int n) {
        //this means:
        //0111  //valid:
        //dp also work:
        //first try with dp:
        //flag, true indicate 1 and false indicate 0:
        string st;
        char prev='\0';
       solve(n,st,prev);
        return ans;
    }
};
