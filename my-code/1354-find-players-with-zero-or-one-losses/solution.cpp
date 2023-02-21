class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> win;
        for(int i=0;i<matches.size();i++){
            int val = matches[i][0];
            win[val]++;
        }

        unordered_map<int,int> loss;
        for(int i=0;i<matches.size();i++){
            int val = matches[i][1];
            loss[val]++;
        }
  
        vector<int> fst;
        for(auto it=win.begin();it!=win.end();++it){
            int val = it->first;
            if(loss.find(val)==loss.end()){
               fst.push_back(val); 
            }
        }
        sort(fst.begin(),fst.end());
        vector<int> sec;
        for(auto it=loss.begin();it!=loss.end();++it){
            if(it->second==1){
                sec.push_back(it->first);
            }
        }
        sort(sec.begin(),sec.end());
        
        vector<vector<int>> real;
        real.push_back(fst);
        real.push_back(sec);
        return real;

    }
};
