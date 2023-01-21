class Solution {
public:
    bool isValid(string sub) {
        if(sub.size()==1)
            return true;
        if(sub.size()>1 && sub[0]!='0' && stoi(sub) <=255)
            return true;
        
        return false;
       
    }
    void dfs(vector<string>& ans, string s, string path, int i, int dots) {
// count number of dots, valid ip cannot have more than 3 dots.
// when end of string is reached and number of dot is 3 (after popping last one) then it is a valid ip
        if(dots==4) {
            if(i == s.length()) {
                path.pop_back();
                ans.push_back(path);
            }
            return; 
        }

        // iterate over next 1 to 3 substrings
        for(int k=1; k<=3; k++) {
            // if substr is >=0 and <=255 
            if(i+k<=s.length() && isValid(s.substr(i,k)))  {;
                dfs(ans, s, path+s.substr(i,k)+'.', i+k, dots+1);
            }
        }
        
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans; 
        string path; 
        dfs(ans, s, path, 0, 0);
        return ans; 
    }
};
