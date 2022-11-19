class Solution {
public:
    int minDifference(vector<int>& nums) {
        //three case banege:
        //->after sort:
        //1->fisrt 1 and last 2 same karo;
        //2->fisrt 2 and last 1 same karo;
        //3->first 3 and last 0 same karo:
        //4->first 0 and last 3 same karo:
        //find minimum differece in all cases:
        
        int n=nums.size();
        if(n<=3) return 0;

        sort(nums.begin(),nums.end());
        
        int mini = INT_MAX;
        for(int i=1;i<=4;i++)
        {
            int val = abs(nums[n-i]-nums[4-i]);  //nums[n-1] ->last and nums[4-1]->first means case 3:
            mini  = min(mini,val);
        }
        return mini;
    }
};
