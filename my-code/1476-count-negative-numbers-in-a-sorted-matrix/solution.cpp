class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt = 0;
        for(vector<int> &v : grid){
            auto x=upper_bound(v.begin(),v.end(),0,greater<int>())-v.begin();
            int number = v.size()-x;
            cnt+=number;
        }
        return cnt;
    }
};
