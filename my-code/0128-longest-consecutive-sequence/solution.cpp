class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int counter=1;
        int j=0;
        int mini = 0;

        if(nums.size()==0){
            return mini;
        }

        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[j]==1){
                counter++;
            }
            if(nums[i]-nums[j]>1){
                mini = max(mini,counter);
                counter=1;
            }
            j++;
        }
        mini = max(mini,counter);
        return mini;
    }
};
