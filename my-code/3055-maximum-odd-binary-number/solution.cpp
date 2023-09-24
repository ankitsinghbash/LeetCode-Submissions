class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int one=0;
        int zero=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                one++;
            }
            else{
                zero++;
            }
        }
        
        string str="";
        if(one>0){
            str+="1";
            one--;
        }
        
        while(zero--){
            str+="0";
        }
        while(one--){
            str+="1";
        }
        
        reverse(str.begin(),str.end());
        
        return str;
    }
};
