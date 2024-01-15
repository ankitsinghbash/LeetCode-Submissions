class Solution {
public:
    vector<int> remove_duplicate(vector<int> &winner){
        vector<int> store;
        int n  = winner.size();    
         for(int i=1;i<winner.size();i++){
             if(winner[i]==winner[i-1]){
                 continue;
             }
             else{
                 store.push_back(winner[i-1]);
             }
         }
         store.push_back(winner[n-1]);
         return store;

    }
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_set<int> st;   //loss:
        vector<vector<int>> result(2);
        vector<int> winn;
        map<int,int> mp;
        sort(matches.begin(),matches.end());
        for(int i=0;i<matches.size();i++){
                  int loss = matches[i][1];
                  int winner = matches[i][0];
                  st.insert(loss);
                  winn.push_back(winner);
                  mp[loss]++;
        }
        
        vector<int> win = remove_duplicate(winn);

        vector<int> ans1;
        for(int i=0;i<win.size();i++){
            int val = win[i];
            if(st.find(val)==st.end()){
                ans1.push_back(val);
            }
        }

        sort(ans1.begin(),ans1.end());
        result[0]=ans1;
        vector<int> ans2;
        for(auto it = mp.begin();it!=mp.end();it++){
            if(it->second==1){
                ans2.push_back(it->first);
            }
        }
       
        result[1]=ans2;
        return result;
    }
};
