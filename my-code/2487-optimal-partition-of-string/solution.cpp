class Solution {
public:
    int partitionString(string s) {
        //play optimally:
        int cnt=0;
        unordered_set<char> st;
        for(int i=0;i<s.size();i++){
            char ch = s.at(i);
            if(st.find(ch)==st.end()){
                st.insert(ch);
            }
            else{
                //present in set:
                st.clear();
                cnt++;
                st.insert(ch);
            }
        }
        cnt++;
        return cnt;

    }
};
