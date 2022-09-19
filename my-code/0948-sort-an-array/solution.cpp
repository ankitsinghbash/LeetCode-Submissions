class Solution {
public:
    void merge(vector<int> &nums, int low, int mid, int high)
    {
        int temp[high+1];
        int i= low, j= mid+1, k=low;
        while(i<= mid && j<= high)
        {
            if(nums[i] < nums[j])
            {
                temp[k]= nums[i];
                i++;
            }
            else if(nums[i] > nums[j])
            {
                temp[k]= nums[j];
                j++;
            }
            else
            {
                temp[k]= nums[i];
                i++;
                k++;
                temp[k]= nums[j];
                j++;
            }
            k++;
        }
        while(i <= mid)
        {
            temp[k]= nums[i];
            k++;
            i++;
        }
        while(j <= high)
        {
            temp[k]= nums[j];
            k++;
            j++;
        }
        for(int i=low; i<= high; i++)
        {
            nums[i]= temp[i];
        }
        return;
    }
    void mergeSort(vector<int> &nums, int low, int high)
    {
        if(low>= high)
        {
            return;
        }
        int mid= low+(high-low)/2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid+1, high);
        merge(nums, low, mid, high);
    }
    
    
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        mergeSort(nums,0,n-1);
        return nums;
    }
};
