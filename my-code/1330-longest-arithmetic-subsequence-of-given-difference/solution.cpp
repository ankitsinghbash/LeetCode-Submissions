class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        unordered_map<int,int> mp;  //map help to reduce jth loop in longest subsequence so time is O(N*2)--->O(n*log(N));
        int maxx = INT_MIN;
        for(auto x : arr){
            int value = x-diff;
            int present = mp[value];
            mp[x] = present+1;
            maxx = max(maxx,mp[x]);
        }
        return maxx;
    }
};
