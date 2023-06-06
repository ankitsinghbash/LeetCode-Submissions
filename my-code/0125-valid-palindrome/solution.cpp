class Solution {
public:




  bool solve(string s){
      string x="";
     for(int i=0;i<s.size();i++){
        char ch = s.at(i);
        char ch1 = tolower(ch);
        int value = (int)(ch1);
        if(ch1>=97 && ch1<=122 || ch1>=48 && ch1<=57){
            x+=ch1;
        }
     
     }
     cout<<"string"<<x<<endl;
     
     //check palinndrome for x:
     int left = 0;
     int right = x.size()-1;
     while(left<=right){
         if(x[left]!=x[right]){
             return false;
         }
         left++;
         right--;
     }
     return true;
  
  }



    bool isPalindrome(string s) {
        return solve(s);
    }
};
