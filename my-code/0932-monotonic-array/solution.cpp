class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
         bool flag1=true;
         bool flag2=false;
        int cnt=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                cnt++;
            }
            if(nums[i]>nums[i-1] && flag1==true){
                  flag2=true;
                  cnt++;
            }
            else if(nums[i]<nums[i-1] && flag2==false){
                  flag1=false;
                  cnt++;
            }
        }
        cout<<cnt<<endl;
        if(cnt==nums.size()-1){
            return true;
        }
        return false;
    }
};
