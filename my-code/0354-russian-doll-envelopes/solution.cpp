class Solution {
public:
    //first ascending order me ho or second descending me when first is same:
    static bool compare(vector<int>&a , vector<int>& b)
    {
      if(a[0]==b[0])
      {
          return a[1]>b[1];  //if first is same then second me a is greater hona chayia:
      }
      else{
          return a[0]<b[0];  //first me b greater hona chayia:
      }
    }
    int maxEnvelopes(vector<vector<int>>&a) {
      sort(a.begin(),a.end(),compare);
      vector<int>dp;
      for(auto i:a)
      {
        auto it=lower_bound(dp.begin(),dp.end(),i[1]);
        if(it==dp.end())
          dp.push_back(i[1]);
        else
          *it=i[1];
      }
      return dp.size();
    }
};
