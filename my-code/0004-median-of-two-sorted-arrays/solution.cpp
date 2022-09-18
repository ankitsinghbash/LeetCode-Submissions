class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
       vector<int> ans;
        for(int i=0;i<nums1.size();i++)
        {
            ans.push_back(nums1[i]);
        }
        
        //add second vector value:
        for(int i=0;i<nums2.size();i++)
        {
            ans.push_back(nums2[i]);
        }
        
        sort(ans.begin(),ans.end());
        //for even number of median:
        if(ans.size()%2==0)
        {
          //even;
           int mid1 = (ans.size()/2)-1;
           int mid2 = ans.size()/2;
           double result = (((double)ans[mid1]+(double)ans[mid2])/2);
           return result;
         }
        else
        {
        //odd;
        int mid = ans.size()/2;
        double result = ((double)ans[mid]);
        return result;
       }
     return -1;
    }
};
