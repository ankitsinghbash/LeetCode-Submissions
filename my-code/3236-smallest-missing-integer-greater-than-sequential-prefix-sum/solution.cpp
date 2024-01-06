class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int len=0;
        int sum=0;
        int n = nums.size();
            int i=0;
            int curr=nums[i];
            int length=1;
            for(int j=i+1;j<n;j++){
                if(nums[j-1]+1==nums[j]){
                   length++;
                   curr+=nums[j];
                }
                else{
                    break;
                }
            }
            if(length>=len){
                length = len;
                sum = max(sum,curr);
            }
        
        
        unordered_set<int> st;
        for(int i=0;i<nums.size();i++){
               st.insert(nums[i]);
        }
        
        int x = sum;
        while(true){
              if(st.find(x)!=st.end()){
                     x++;
              }
              if(st.find(x)==st.end()){
                    break;
              }
        }
        return x;
        
    }
};
