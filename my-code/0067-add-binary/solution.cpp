class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.size()-1;
        int j=b.size()-1;
        int carry=0;
        vector<int> ans;
        while(i >= 0 || j >= 0 || carry) {
            if(i >= 0) {
                carry += a[i] - '0';
                i--;
            }
            
            if(j >= 0) {
                carry += b[j] - '0';
                j--;
            }
            
            int rem = (carry % 2);
            ans.push_back(rem);
            carry = carry / 2;
        }
        
        string str;
        reverse(ans.begin(),ans.end());
        for(auto &x : ans){
            str+=to_string(x);
        }
        return str;
    }
};
