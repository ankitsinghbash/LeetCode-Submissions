class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        int m = nums1.size();
        vector<int> arr_nextgreater(nums2.size(),-1);
        stack<int> st;
        st.push(nums2[n-1]);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && nums2[i]>=st.top()){
                st.pop();
            }
            if(st.empty()){
                arr_nextgreater[i]=-1;
            }
            else{
                arr_nextgreater[i]=st.top();
            }
            st.push(nums2[i]);
        }


    vector<int> ans;
    for(int i=0;i<nums1.size();i++){
        int val = nums1[i];
        //find val in nums2 give index idx:
        int idx = find(nums2.begin(),nums2.end(),val)-nums2.begin();
        ans.push_back(arr_nextgreater[idx]);

    }
    return ans;
    }
};
