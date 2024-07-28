class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int singlesum =0;
        int doublesum = 0;
        for(int i=0;i<nums.size();i++){
             string x = to_string(nums[i]);
            if(x.size()>1){
                doublesum+=nums[i];
            }
            else{
                singlesum+=nums[i];
            }
        }
        
        if(singlesum>doublesum || doublesum>singlesum){
            return true;
        }
        return false;
    }
};
