class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> t_box(26);
        vector<int> s_box(26);
        for(int i=0;i<t.size();i++){
             int idx = t[i]-'a';
             t_box[idx]++;
        }
        int cnt=0;
        for(int i=0;i<s.size();i++){
              int idx1 = s[i]-'a';
              if(t_box[idx1]>0){
                  t_box[idx1]--;
              }
              else{
                  cnt++;
              }
        }
        return cnt;
    }
};
