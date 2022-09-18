class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> v(n);
        sort(nums.begin(),nums.end());
        int i=1;
        int j=nums.size()-1;
        while(i<n)
        {
            v[i]=nums[j];
            i=i+2;
            j--;
        }
        
        i=0;
        while(i<n)
        {
            v[i]=nums[j];
            i=i+2;
            j--;
        }
        
        for(int i=0;i<n;i++)
        {
            nums[i]=v[i];
        }
        
        
    }
};
