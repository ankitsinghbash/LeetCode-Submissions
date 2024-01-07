class Solution {
public:
    int solve(vector<int> &arr){
        int low=0;
        int high = arr.size()-1;
        int result = -1;
        while(low<high){
            int mid = low+(high-low)/2;
            if(arr[mid]<=arr[mid+1]){
                low  = mid+1;
            }
            else{
                //arr[mid]>arr[mid+1];
                high = mid;
                result  = mid;
            }
        }
        return result;
    }
    int peakIndexInMountainArray(vector<int>& arr) {
        return solve(arr);
    }
};
