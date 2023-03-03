class Solution {
public:
    int strStr(string str2, string str1) {
       int pos=0;
       int index;
       while((index=str2.find(str1))!=string::npos){

                 pos=index+1;
                 return pos-1;
       }
       return -1;
    }
};
