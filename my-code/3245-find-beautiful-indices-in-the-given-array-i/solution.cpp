class Solution {
public:
   vector<int> solve(string &s,string a) {
    vector<int> ans;
    
    size_t pos=s.find(a); // Find the first occurrence of string 'a' in 's'
    while (pos != string::npos) {
        ans.push_back(pos);
        pos = s.find(a, pos + 1); // Find the next occurrence of string 'a' in 's'
    }
    return ans;
   }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        if(s.size() < a.size() || s.size() < b.size()) return {};
        
        vector<int> ans;
        
        vector<int> index_a = solve(s, a);
        vector<int> index_b = solve(s, b);
        
        
        int i=0;
        int j=0;
        while (i<index_a.size()&&j<index_b.size()) {
            int diff=abs(index_a[i]-index_b[j]);
            if (diff <= k) {
                ans.push_back(index_a[i]);
                i++;  
            } else if (index_a[i] < index_b[j]) {
                i++;  
            } else {
                j++;  
            }
        }
        return ans;
    
    }
};
