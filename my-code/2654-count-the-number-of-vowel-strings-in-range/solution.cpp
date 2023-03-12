class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int cnt=0;
        for(int i=left;i<=right;i++){
            string str = words[i];
            int ll = 0;
            int rr = str.size()-1;
            if(str[ll]=='a' || str[ll]=='e' || str[ll]=='i' || str[ll]=='o' || str[ll]=='u'){
                if(str[rr]=='a' || str[rr]=='e' || str[rr]=='i' || str[rr]=='o' || str[rr]=='u'){
                cnt++;
            }
            }
        }
        return cnt;
    }
    
};
