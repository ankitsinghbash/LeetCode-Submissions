class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> first;
        vector<int> second;
        
        int idx1=0;
        int idx2=0;
        first.push_back(nums[idx1]);
        second.push_back(nums[idx2+1]);
            
        for(int i=2;i<nums.size();i++){
                 if(first[idx1]>second[idx2]){
                     first.push_back(nums[i]);
                     idx1++;
                 }
                else{
                    second.push_back(nums[i]);
                    idx2++;
                }
        }
        
        
        
        vector<int> result;
        for(int i=0;i<first.size();i++){
            result.push_back(first[i]);
        }
          for(int i=0;i<second.size();i++){
            result.push_back(second[i]);
        }
        return result;
    }
};
