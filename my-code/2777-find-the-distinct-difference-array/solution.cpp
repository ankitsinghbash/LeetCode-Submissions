class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s1;
        unordered_set<int> s2;
        vector<int> cnt1(n);
        vector<int> cnt2(n+1);
        for(int i=0;i<nums.size();i++){
            s1.insert(nums[i]);
            cnt1[i]=s1.size();
            s2.insert(nums[n-i-1]);
            cnt2[i]=s2.size();
        }
        reverse(cnt2.begin(),cnt2.begin()+n);
        cnt2[n]=0;
        for(auto x : cnt1){
            cout<<x<<" ";
        }
        cout<<endl;
        for(auto x : cnt2){
            cout<<x<<" ";
        }
        
        vector<int> ans;
        for(int i=0;i<n;i++){
            int val = cnt1[i]-cnt2[i+1];
            ans.push_back(val);
        }
        return ans;
    }
};
