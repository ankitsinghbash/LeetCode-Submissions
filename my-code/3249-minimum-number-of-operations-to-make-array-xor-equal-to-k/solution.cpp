class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
          int first = nums[0];
          for(int i=1;i<nums.size();i++){
                  first = first^nums[i];
          }

          string binary_first = bitset<32>(first).to_string();
          string binary_second = bitset<32>(k).to_string();
         
          int cnt=0;
          for(int i=0;i<32;i++){
               if(binary_first[i]!=binary_second[i]){
                cnt++;
               }
          }
          return cnt;
    }
};
