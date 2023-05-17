class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> store;
        int i=0;
        int j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<=nums2[j]){
                store.push_back(nums1[i]);
                i++;
            }
            else if(nums1[i]>nums2[j]){
                store.push_back(nums2[j]);
                j++;
            }
        }

        while(i<nums1.size()){
            store.push_back(nums1[i]);
            i++;
        }

        while(j<nums2.size()){
            store.push_back(nums2[j]);
            j++;
        }

        int size = store.size();
        int low  = 0;
        int high = store.size()-1;
        if(size%2==0){
            int mid = low+(high-low)/2;
            double total = store[mid]+store[mid+1];
            double ans = total/2;
            return ans;
        }
        else{
            int mid = low+(high-low)/2;
            double total = store[mid];
            double ans = total/1.0;
            return ans;
        }
    }
};
