class Solution {
public:
    string countAndSay(int n) {
       if(n==1)
        {
            return "1";
        }
        string s  = countAndSay(n-1);
        string str="";
        int counter=0;
        for(int i=0;i<s.length();i++)
        {
            counter++;
            if(i==s.length()-1||s.at(i)!=s.at(i+1))
            {
                str=str+to_string(counter)+s.at(i);
                counter=0;
            }
        }
        return str;
    }
};
