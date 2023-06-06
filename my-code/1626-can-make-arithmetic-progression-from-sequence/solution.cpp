class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        //brute force:
        sort(arr.begin(),arr.end());
        int initial = arr[1]-arr[0];
        for(int i=1;i<arr.size();i++){
            int diff = arr[i]-arr[i-1];
            if(diff!=initial){
                return false;
            }
        }
        return true;
    }
};
