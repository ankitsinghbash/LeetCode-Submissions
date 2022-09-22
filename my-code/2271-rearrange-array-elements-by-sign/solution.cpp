class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        vector<int> pos;  //pos store the positive value:
        vector<int> nos;   //nos store the negative value:
        
        
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>=0)
            {
                //positive:
                pos.push_back(nums[i]);
            }
            else
            {
                nos.push_back(nums[i]);
            }
        }
        
        int posSize =  pos.size();
        int nosSize = nos.size();
        int i=0;  //i for pos size;
        int j=0;   //j for nos size;
        int k=0;
        while(k<nums.size())
        {
            if(i<posSize && j<nosSize)
            {
                nums[k++]=pos[i++];
                nums[k++]=nos[j++];
            }
            else if(i<posSize)  //rest element jo pos me rhe gya:
            {
               nums[k++]=pos[i++];
            }
            else if(j<nosSize)   //rest element jo nos me rhe gya:
            {
                nums[k++]=nos[j++];
            }
        }
        return nums;
    }
};
