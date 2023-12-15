class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> st;
        for(int i=0;i<paths.size();i++){
            string start = paths[i][0];
            string end = paths[i][1];

            st.insert(start);
            st.insert(end);
        }
      
        unordered_map<string,int> mp;
        for(auto x : st){
            mp[x]=0;
        }

        for(int i=0;i<paths.size();i++){
            string start = paths[i][0];
            string end = paths[i][1];

            mp[start]++;
        }

        string ans="";
        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->second==0){
                return it->first;
            }
        }
        return ans;

    }
};
