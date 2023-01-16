class Solution {
public:
   
   static bool cmp(const pair<int,int> &a,const pair<int,int> &b){
       return a.first<b.first;
   }
   
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<pair<int,int>> pr;
        for(int i=0;i<intervals.size();i++){
                auto p = make_pair(intervals[i][0],intervals[i][1]);
                pr.push_back(p);
        }
        auto prr = make_pair(newInterval[0],newInterval[1]);
        pr.push_back(prr);
        sort(pr.begin(),pr.end(),cmp);
  
        //now sort karo pr as according to first value:
        vector<pair<int,int>> ans;
        pair<int,int>  temp  = pr[0];
        for(int i=0;i<pr.size();i++){
             if(temp.second>=pr[i].first){
                  temp.second = max(pr[i].second,temp.second);
             }
             else{
                  ans.push_back(temp);
                  temp = pr[i];
             }
        }
        ans.push_back(temp);
        vector<vector<int>> v2;
        for(int i=0;i<ans.size();i++){
            vector<int> v1;
            v1.push_back(ans[i].first);
            v1.push_back(ans[i].second);
            v2.push_back(v1);
            v1.clear();
        }
       return v2;
    }
};
