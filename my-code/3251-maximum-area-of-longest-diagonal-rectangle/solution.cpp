class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        vector<pair<double,pair<int,int>>> vec;
        for(int i=0;i<dimensions.size();i++){
             int a = dimensions[i][0];
            int b = dimensions[i][1];
            double diagnol = sqrt(a*a+b*b);
            vec.push_back({diagnol,{a,b}});
        }
        sort(vec.begin(),vec.end());
        int n = vec.size()-1;
        pair<double,pair<int,int>> last = vec[n];
        
        double last_value = last.first;
        int w = last.second.first;
        int h = last.second.second;
        int maxxarea=w*h;
        
        for(int i=vec.size()-1;i>=0;i--){
            if(vec[i].first!=last_value){
                break;
            }
            
            int w = vec[i].second.first;
            int h = vec[i].second.second;
            int curr=w*h;
            maxxarea = max(maxxarea,curr);
            
        }
        
        
        return maxxarea;
    }
};
