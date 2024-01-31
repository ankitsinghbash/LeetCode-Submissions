class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int,int>> st;
        int n = temp.size();
        vector<int> ans(n,0);
        st.push({temp[n-1],n-1});
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && st.top().first<=temp[i]){
                st.pop();
            }
            if(st.size()==0){
                ans[i]=0;
            }
            else{
                int val = st.top().second-i;
                ans[i]=val;
            }
            st.push({temp[i],i});
        }
        return ans;
    }
};
