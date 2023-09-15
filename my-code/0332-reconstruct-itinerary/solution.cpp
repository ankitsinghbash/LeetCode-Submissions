class Solution {
public:
    vector<string> result;
    bool solve(string start,unordered_map<string,vector<string>> &adj,vector<string> path,vector<vector<string>> &tickets){
  
        path.push_back(start); //push_value so we start to add path:
        if(path.size()==tickets.size()+1){ //base case:
            result = path;
            return true;
        }

        vector<string> &vec = adj[start]; //always taken with reference otherwise it forget the actual value in the backtracking:
        for(int i=0;i<vec.size();i++){
            string to_City = vec[i];
            //remove for loop case:
            vec.erase(vec.begin()+i);
            if(solve(to_City,adj,path,tickets)==true){
                return true;
            }
            vec.insert(vec.begin()+i,to_City);
        }
        path.pop_back();  //backtracking same also in graph:
        return false;

    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>> adj;
        for(int i=0;i<tickets.size();i++){
            string from = tickets[i][0];
            string to = tickets[i][1];
            adj[from].push_back(to);
        }
     
       
        for(auto it=adj.begin();it!=adj.end();it++){
            sort(it->second.begin(),it->second.end());
        }


        vector<string> path;
        solve("JFK",adj,path,tickets);
        return result;
    }
};
