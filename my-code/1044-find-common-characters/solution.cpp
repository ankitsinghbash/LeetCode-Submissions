class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> temp1(26);
        for(int i=0;i<words[0].size();i++){
             int idx = words[0][i]-'a';
             temp1[idx]++;
        }


        vector<int> cnt;
        for(int i=1;i<words.size();i++){
            string str = words[i];
            vector<int> temp2(26,0);
            for(int i=0;i<str.size();i++){
                int idx = str[i]-'a';
                temp2[idx]++;
            }

            vector<int> temp3(26,0);
            for(int i=0;i<26;i++){
                temp3[i] = min(temp1[i],temp2[i]);
            }
            temp1 = temp3;
            cnt = temp3;
        }

        vector<string> ans;
        for(int i=0;i<26;i++){
            int time = cnt[i];
            for(int j=0;j<time;j++){
                char ch = i+'a';
                string st(1,ch);
                ans.push_back(st);
            }
        }
        
        return ans;
    }
};
