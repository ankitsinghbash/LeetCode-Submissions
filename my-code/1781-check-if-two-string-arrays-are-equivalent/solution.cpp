class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i=0;
        int j=0;
        int cnt1=0;
        int cnt2=0;
        while(i<word1.size() && j<word2.size()){
            if(word1[i][cnt1]!=word2[j][cnt2]){
                return false;
            }
            cnt1++;
            cnt2++;
            if(cnt1==word1[i].size()){
                cnt1=0;
                i++;
            }
            if(cnt2==word2[j].size()){
                cnt2=0;
                j++;
            }
        }

        if(i==word1.size() && j==word2.size()){
            return true;
        }
        return false;



    }
};
