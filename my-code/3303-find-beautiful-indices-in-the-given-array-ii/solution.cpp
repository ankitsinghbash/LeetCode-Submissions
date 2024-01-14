class Solution {
public:
    vector<int> solve(string &s,string &a){
        vector<int> ans;
        int n = s.size();
        vector<int> pref(a.size(),0);
        for(int i=1,j=0;i<a.size();i++){
            while(j>0 && a[i]!=a[j]){
                j = pref[j-1];
            }
            if(a[i]==a[j]){
                j++;
            }
            pref[i]=j;
        }
        for(int i=0,j=0;i<n;i++){
            while(j>0 && s[i]!=a[j]){
                j=pref[j-1];
            }
            if(s[i]==a[j]){
                j++;
            }
            int len = a.size();
            if(j==len){
                ans.push_back(i-len+1);
                j=pref[j-1];
            }
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
