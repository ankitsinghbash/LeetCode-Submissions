class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> result(n+m,0);
        int i=0;
        int j=0;
        int k=0;
        while(i<n && j<m){
            if(nums1[i]<=nums2[j]){
                result[k]=nums1[i];
                k++;
                i++;
            }
            else{
                result[k]=nums2[j];
                j++;
                k++;
            }
        }

        while(i<n){
            result[k]=nums1[i];
            k++;
            i++;
        }
        while(j<m){
            result[k]=nums2[j];
            j++;
            k++;
        }

        if((n+m)%2!=0){
              int idx = (n+m)/2;
              return (double)result[idx];
        }

        //odd:
        int idx1 = (n+m)/2;
        int idx2 = idx1-1;
        double data = (double)(result[idx1]+result[idx2])/2;
        return data;
    }
};
