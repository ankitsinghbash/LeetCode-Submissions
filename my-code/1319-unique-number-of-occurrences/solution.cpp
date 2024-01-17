class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;                   
        }
        vector<int> vec;
        for(auto it = mp.begin();it!=mp.end();it++){
            vec.push_back(it->second);     
        }
        unordered_set<int> st;
        for(int i=0;i<vec.size();i++){
            int val=vec[i];                       
            if(st.find(val)!=st.end()) return false;  
            st.insert(val);
        }
        return true;

      
    }
};
