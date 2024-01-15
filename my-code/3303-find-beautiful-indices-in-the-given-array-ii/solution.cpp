class Solution {
public:
    vector<int> solve(string &s,string &pattern){
      
        int m = pattern.size();
        vector<int> lsp(m,0);
        int i=1;
        int len=0;                 //aca
        while(i<m){
            if(pattern[i]==pattern[len]){
                len++;
                lsp[i]=len;
                i++;
            }
            else{
                if(len!=0){
                    len = lsp[len-1];
                }
                else{
                    lsp[i]=0;
                    i++;
                }
            }
        }
        
        
        //Now apply kmp algo:
        vector<int> result;
        i=0;
        int j=0;
        int n = s.size();
        while(i<n){
            if(s[i]==pattern[j]){
                i++;
                j++;
            }
            if(j==m){
                result.push_back(i-j);
                j = lsp[j-1];
            }
            else if(i<n && s[i]!=pattern[j]){
                if(j!=0){
                 j = lsp[j-1];
                }
                else{
                    i++;
                }
            }
        }
        
        return result;
        
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
