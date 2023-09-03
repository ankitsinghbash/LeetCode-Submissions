class Solution {
public:
    typedef long long ll;
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
     int s = nums.size();
     vector<int> ps(s + 1, 0);
     unordered_map<int, int> c;
     ps[0]=0;
     c[0] = 1;
     ll r = 0;

    for(int i=0;i<s;i++) {
      ps[i+1] = (ps[i]+(nums[i]%modulo==k?1:0))%modulo;
      int cmpl=(ps[i+1]-k+modulo)%modulo;
     r+= c[cmpl];
     c[ps[i + 1]]++;
    }
     return r;
    }
};
