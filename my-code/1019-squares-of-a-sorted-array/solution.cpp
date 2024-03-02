class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int idx = n-1;
        int i=0;
        int j=n-1;
        while(i<=j){
            int data1 = nums[i]*nums[i];
            int data2 = nums[j]*nums[j];
            if(data2>=data1){
                ans[idx]=data2;
                idx--;
                j--;
            }
            else{
                ans[idx]=data1;
                idx--;
                i++;
            }
        }
        return ans;
    }
};
