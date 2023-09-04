class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);
        int start=0;
        int last = str.size()-1;
        while(start<=last){
            if(str[start]!=str[last]){
                return false;
            }
            start++;
            last--;
        }
        return true;
    }
};
