class Solution {
public:
    vector<string> ans;
    
    // static bool cmp(pair<int,string> &v1,pair<int,string> &v2){
    //     return v1.first>v2.first;
    // }
    
    
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>> p;
        int n=names.size();
        for(int i=0;i<n;i++){
            p.push_back({heights[i],names[i]});
        }
        
        sort(p.begin(),p.end(),greater<pair<int,string>>());
        for(auto x : p){
            string str = x.second;
            ans.push_back(str);
        }
        return ans;
    }
};
