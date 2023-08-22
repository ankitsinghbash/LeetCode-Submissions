class Solution {
public:
     vector<char> ref = {',','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    string convertToTitle(int columnNumber) {
        string str="";
        while(columnNumber>0){
            int rem = (columnNumber-1)%26;   //similar to decimal number system: -1 becuase dry run if columnNumber=26 it balance my that:
            str+=ref[rem+1];    //we use any method: //like also:   //str+=('A'+rem);                    
            columnNumber=(columnNumber-1)/26;
        }
        reverse(str.begin(),str.end()); //notice it decimal system 12 we get remainber from last like 2 then 1 for recorrect it again reverse it: that why i use reverse str here also:
        return str;
    }
};
