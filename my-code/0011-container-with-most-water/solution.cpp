class Solution {
public:
    int maxArea(vector<int>& arr) {
        int low = 0;
        int high = arr.size()-1;
        int maxx = 0;

        while(low<high){
           int mini = min(arr[low],arr[high]);
           int water = (high-low)*mini;
           maxx = max(maxx,water);
           if(arr[low]<=arr[high]){
               low++;
           }
           else{
               high--;
           }
        }
        return maxx;
    }
};
