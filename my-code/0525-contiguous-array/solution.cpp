class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;   //sum vs index:
        mp[0] = -1;  
        int currsum=0;
        int maxlen=0;
        for(int i=0;i<nums.size();i++){
              currsum += (nums[i]==1?1:-1);
              if(mp.find(currsum)!=mp.end()){
                        maxlen  = max(maxlen,i-mp[currsum]);
              }
              else{
                      mp[currsum]=i;
              }

        }
        return maxlen;
    }

};
