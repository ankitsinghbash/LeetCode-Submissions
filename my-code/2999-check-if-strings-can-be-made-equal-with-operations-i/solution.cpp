class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int n = s1.size();
        for(int i=0;i<n-2;i++){
            char ch1=s1.at(i);
            char ch2 = s2.at(i);
            if(ch1!=ch2){
                swap(s1[i],s1[i+2]);
            }
            if(s1==s2){
                return true;
            }
        }
        return false;
    }
};
