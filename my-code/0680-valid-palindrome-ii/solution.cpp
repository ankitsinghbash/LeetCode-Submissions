class Solution {
public:
    bool check(int i,int j,string &s){
    
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i=0;
        int j = s.size()-1;
        string str;
        while(i<j){
            if(s[i]!=s[j]){
                   for(int start=i;start<=j;start++){
                       str+=s[start];
                   }
                   break;
            }
            i++;
            j--;
        }
  
       i = 0;
       j = str.size()-1;
        if(str.size()==0) return true;

        return check(1,j,str) || check(0,j-1,str);

       
    }
};

//deeee
