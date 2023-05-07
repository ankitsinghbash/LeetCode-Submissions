class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& arr){
        int n = arr.size();
        vector<int> result(n);
        vector<int> store;
        for(int i=0;i<n;i++){
            //upper bound of val-> in store
            int idx = upper_bound(store.begin(),store.end(),arr[i])-store.begin();
            if(idx==store.size()){
                 store.push_back(arr[i]);
            }
            else{
                 store[idx]=arr[i];
            }
            result[i] = idx+1;
        }
        return result;
    }
};
//Idea store -> index+1 is my answer: and try to eleminate the arr[i] value to store as ascending order:
//store[idx] = x ; //idx represent the LIS OF upto and x represent the elment:


//tle:
// class Solution {
// public:
//     vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
//         longest subsequence dp:
//         first with simple dp:
//         int n = obstacles.size();
//         vector<int> dp(n,1);
//         for(int i=0;i<n;i++){
//             for(int j=0;j<i;j++){
//                 if(obstacles[j]<=obstacles[i]){
//                   dp[i]=max(dp[i],dp[j]+1);
//                 }
//             }
//         }
//         return dp;
//     }
// };
