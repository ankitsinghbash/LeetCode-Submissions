class Solution {
public:
    string largestOddNumber(string s) {
        int j = s.size()-1;
        int last=-1;
        while(j>=0){
            char ch = s.at(j);
            int val = ch-'0';
            if(val%2!=0){
                last = j;
                break;
            }
            j--;
        }
  
       string str = s.substr(0,last+1);
       return str;

    }
};
