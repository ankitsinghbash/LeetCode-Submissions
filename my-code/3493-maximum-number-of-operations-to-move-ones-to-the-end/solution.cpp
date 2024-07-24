class Solution {
public:
    int maxOperations(string s) {
        //greedy approach:
        int oldone=0;
        int ans=0;
        int i=0;
        while(i<s.size()-1){
            if(s[i]=='1'){
                oldone++;
            }
            if(s[i]=='1' && s[i+1]=='0'){
                ans+=oldone;
            }
            i++;
        }
        return ans;
        
        
        //10011001
        //00111001:
    }
};
