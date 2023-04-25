class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();
        int sum=0;
        for(int i=0;i<rolls.size();i++){
            sum+=rolls[i];
        }
  
        int total = mean*(m+n)-sum;
        if(total>6*n || total<1*n){
            return {};
        }

        //distribut total into n peple:
        int minicost = total/n;
        vector<int> ans(n,minicost);
        int rest = total%n;
        for(int i=1;i<=rest;i++){
              ans[i]+=1;
        }
     
        return ans;
    }
};
