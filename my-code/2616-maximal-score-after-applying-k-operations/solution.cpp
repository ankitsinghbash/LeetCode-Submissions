class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long> p;

        for(auto &x : nums){
            p.push(x);
        }

          long long ans=0;
          for(int i=0;i<k;i++){
              int val = p.top();
              p.pop();
              ans+=val;
              p.push(ceil(double(val/3.0)));
          }
          return ans;
    }
};
