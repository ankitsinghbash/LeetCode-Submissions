class Solution {
public:
    string getEncryptedString(string s, int k) {
          /*
             Input: s = "dart", k = 3

Output: "tdar"
          */
        //basically rotate string:
        vector<char> vec;
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            vec.push_back(ch);
        }
        
        int n = vec.size();
        string ans;
        for(int i=0;i<vec.size();i++){
            int x =  ((i+k)%n);
            ans+=(vec[x]);
        }
        
        
       return ans;

    }
};
