class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(2,0);
        unordered_set<int> st;
        for(int i=0;i<nums2.size();i++){
            st.insert(nums2[i]);
            
        }
        
        int counter=0;
        for(int i=0;i<nums1.size();i++){
            int val = nums1[i];
            if(st.find(val)!=st.end()){
                counter++;
            }
        }
        ans[0]=counter;
        
        unordered_set<int> st2;
        for(int i=0;i<nums1.size();i++){
            st2.insert(nums1[i]);
        }
        
        int counter2=0;
        for(int i=0;i<nums2.size();i++){
            int val = nums2[i];
            if(st2.find(val)!=st2.end()){
                counter2++;
            }
        }
        ans[1]=counter2;
        return ans;
    }
};
