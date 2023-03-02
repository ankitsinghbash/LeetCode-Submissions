class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        int n=chars.size();
        vector<char> ans;
        while(i<n){
            char ch = chars[i];
            int cnt=0;
            while(i<n && ch==chars[i]){
                i++;
                cnt++;
            }
        
         ans.push_back(ch);
         if(cnt>1){
           string str = to_string(cnt);
           for(auto &x : str){
               ans.push_back(x);
           }
         }      

        }
        chars.clear();
        for(auto &x : ans){
            chars.push_back(x);
        }
        return ans.size();
    }
};
