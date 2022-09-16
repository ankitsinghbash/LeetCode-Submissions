class Solution {
public:
    void reverseString(vector<char>& s) {
        
        vector<char> second;
        for(int i=s.size()-1;i>=0;i--)
        {
            second.push_back(s[i]);
        }
        
        for(int i=0;i<second.size();i++)
        {
            s[i]=second[i];
        }
        
    }
};
