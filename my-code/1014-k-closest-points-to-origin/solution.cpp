class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>  > p;   //sort from high to low:
        for(int i=0;i<points.size();i++){
            int x = points[i][0];
            int y = points[i][1];
            int dist = pow(x,2)+pow(y,2); //dont store exact value after sqrt root [[9997,9997],[9996,9998]] have same root in float data type: flaot give upto 4 decimal only:
            p.push({dist,{x,y}});
        }

        while(k--){
           vector<int> sm;
           auto Top = p.top();
           p.pop();
           cout<<Top.first<<endl;
           pair<int,int> S = Top.second;
           sm.push_back(S.first);
           sm.push_back(S.second);
           ans.push_back(sm);
        }
        return ans; 
    }
};
