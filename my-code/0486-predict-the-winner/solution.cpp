class Solution {
public:
    
    int solve(int i,int j,vector<int> &nums,int total,bool flag){
 
        if(j<i){
            return 0;
        }

        if(flag==true){
           total+=max(nums[i]+solve(i+1,j,nums,total,false),nums[j]+solve(i,j-1,nums,total,false));
        }
        else{
           total+=min(-nums[i]+solve(i+1,j,nums,total,true),-nums[j]+solve(i,j-1,nums,total,true));
        }

        return total;

          
    }


    bool predictTheWinner(vector<int>& nums) {
        int i=0;
        int j= nums.size()-1;
        int total=0;
        return solve(i,j,nums,0,true)>=0;
    }
};
