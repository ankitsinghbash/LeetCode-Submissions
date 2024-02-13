class Solution {
public:
    bool check(string str){
        int low=0;
        int high = str.size()-1;
        while(low<=high){
            if(str[low]!=str[high]){
                return false;
            }
            low++;
            high--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        //brute force:
        string ans="";
        for(int i=0;i<words.size();i++){
            string str = words[i];
            if(check(str)==true){
                ans=str;
                break;
            }
        }
        return ans;
    }
};
