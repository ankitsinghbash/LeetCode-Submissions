class Solution {
public:

    struct  cmp{
        bool operator()(const pair<int,pair<int,int>> &a,const pair<int,pair<int,int>> &b){
                  if(a.first==b.first){
                      pair<int,int> P = a.second;
                      pair<int,int> PP = b.second;

                      int val1 = P.first;
                      int val2 = PP.first;
                      return val1>val2;
                  }
                  else if(a.second.first==b.second.first){
                      return b.second.second>a.second.second;
                  }
                  return a.first<b.first;
        }

    };

    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> ans;
        vector<pair<int,pair<int,int>>> X;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                int val = i+j;
                X.push_back({val,{i,j}});
            }
        }
 
        sort(X.begin(),X.end(),cmp());

        for(int i=0;i<X.size();i++){
            pair<int,pair<int,int>> F = X[i];
            pair<int,int> delta = F.second;
            int x = delta.first;
            int y = delta.second;
            ans.push_back(nums[x][y]);
       
        }

        return ans;

    }
};
