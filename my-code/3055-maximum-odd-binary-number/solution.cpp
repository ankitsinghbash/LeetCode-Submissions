class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int total_one=0;
        for(int i=0;i<s.size();i++){
            char ch = s.at(i);
            if(ch=='1'){
                total_one++;
            }
        }
        string str;
        int restone = total_one-1;
        int n = s.size()-1;
        while(n--){
            if(restone>0){
                str+='1';
                restone--;
            }
            else{
                str+='0';
            }
        }
        str+='1';
        return str;
    }
};


