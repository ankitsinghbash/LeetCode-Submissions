class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt = 0;
        for(auto x : details){
            string str = x;
            string s = str.substr(11,2);
            int val = stoi(s);
            if(val>60){
                cnt++;
            }
        }
        return cnt;
    }
};
