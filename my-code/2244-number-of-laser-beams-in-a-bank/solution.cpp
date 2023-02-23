class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> ans;
        for(int i=0;i<bank.size();++i){
            int cnt=0;
            for(int j=0;j<bank[i].size();++j){
                if(bank[i][j]=='1'){
                   cnt++;
                }
            }
            if(cnt!=0){
                ans.push_back(cnt);
            }
        }
        int result = 0;
        for(int i=1;i<ans.size();++i){
            int val = ans[i]*ans[i-1];
            result+=val;
        }
        return result;
    }
};
