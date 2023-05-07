class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        //brute force:
        vector<string> store;
        //generate all substring of word:
        for(int i=0;i<word.size();i++){
            for(int j=1;j<=word.size()-i;j++){
                store.push_back(word.substr(i,j));
            }
        }

        int cnt = 0;
        for(int i=0;i<patterns.size();i++){
            string s = patterns[i];
            for(int j=0;j<store.size();j++){
                if(s==store[j]){
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};
