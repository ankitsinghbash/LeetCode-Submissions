class Solution {
public:
    int minimumChairs(string s) {
        int ans=0;
        int current_chair=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='E'){
                current_chair++;
                ans = max(ans,current_chair);
            }
            else{
                current_chair--;
            }
        }
        return ans;
    }
};


/*
i have LLE:


*/
