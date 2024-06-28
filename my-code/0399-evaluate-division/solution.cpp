class Solution {
public:
    double dfs(string start,string final,unordered_map<string,vector<pair<string,double>>> &mp,unordered_set<string> &st){
            

             if(start==final) return  1.0;  


            
 
             st.insert(start);   //true:
             for(auto &x : mp[start]){
                  string v = x.first;
                  double cost = x.second;

                  if(st.find(v)==st.end()){  //means unvisited:
                       double result = dfs(v,final,mp,st);
                       if(result!=-1.0){
                           return result*cost;
                       } 
                  }

             }
             return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>> mp;
        for(int i=0;i<equations.size();i++){
             double current_cost = values[i];
             string u = equations[i][0];
             string v = equations[i][1];

             mp[u].push_back({v,current_cost});
             double alt_current_cost = 1.0/current_cost;
             mp[v].push_back({u,alt_current_cost});
        } 


        
         vector<double> ans;
         for(int i=0;i<queries.size();i++){
             string start = queries[i][0];
             string end = queries[i][1];
             unordered_set<string> st;  //for checking the visited or not:
             if(mp.find(start)==mp.end() || mp.find(end)==mp.end()){
              ans.push_back(-1.0);
             }
             else{
               double get_cost = dfs(start,end,mp,st);
               ans.push_back(get_cost);
             }
         }
         return ans;


    }
};
