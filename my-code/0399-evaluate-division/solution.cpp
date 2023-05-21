class Solution {
public:
  
  void dfs(unordered_map<string,vector<pair<string,double>>> &adj,string N,string D,double &cost,unordered_set<string> &st,double product){
       if(st.find(N)!=st.end()) return;    
 

        st.insert(N);
        if(N==D){
            cost = product;
            return;
        }
 
   
        for(auto &v : adj[N]){
                if(st.find(N)!=st.end()){
                string f = v.first;
                double s = v.second;
                dfs(adj,f,D,cost,st,product*s);
                }
        }

  }




    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>> adj;
        for(int i=0;i<equations.size();i++){
            string u = equations[i][0];
            string v = equations[i][1];

            double w = values[i];
            adj[u].push_back({v,w});
            adj[v].push_back({u,1/w*1.0});
        }

        vector<double> ans;
        for(int i=0;i<queries.size();i++){
            string N = queries[i][0];
            string D = queries[i][1];
   
            auto it1=adj.find(N);
            auto it2=adj.find(D);
            double val = -1.0;
            double product =  1.0;
            if(it1!=adj.end()){     //This part has various way to write but write in an efficient way:
                 unordered_set<string> st;     //for below input a-->c kabhi nahi paucha add -1.0 in answer:
                 dfs(adj,N,D,val,st,product);
            }
            ans.push_back(val);
        }
        return ans;

    }
};

/*Dry run for this input:
[["a","b"],["c","d"]]
[1.0,1.0]
[["a","c"],["b","d"],["b","a"],["d","c"]]
*/
