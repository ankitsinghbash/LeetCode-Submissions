class Solution {
public:
    typedef pair<int,string> ll;
   
    struct cmp{
        bool operator()(pair<int,string> &a,pair<int,string> &b){
                  return a.first>b.first;
        }
    };


    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
          //compartor sorting:
          vector<ll> vec;
          int n = names.size();
          for(int i=0;i<n;i++){
            vec.push_back({heights[i],names[i]});
          }

          sort(vec.begin(),vec.end(),cmp());

         vector<string> ans;
          for(int i=0;i<n;i++){
              ans.push_back(vec[i].second);
          }
          return ans;
    }
};
