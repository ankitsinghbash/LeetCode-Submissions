class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //bits masking //codestory with mike:
        int result =0;
        for(int k=0;k<=31;k++){
            int temp=(1<<k);
            int cnt_one = 0;
            int cnt_zero =0;

            for(auto x: nums){
                if((x&temp)==0){
                    cnt_zero++;
                }
                else{
                    cnt_one++;
                }
            }
            if(cnt_one%3==1){
                result = (result|(1<<k));
            }
        }
        return result;

    }
};
