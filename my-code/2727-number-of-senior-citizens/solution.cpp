class Solution {
public:
    int countSeniors(vector<string>& details) {
         int cnt=0;
           
        for(int i=0;i<details.size();i++){
             int ten = details[i][11]-'0';
             int one = details[i][12]-'0';
             int value = ten*10+one;
             if(value>60) cnt++;

        }



         return cnt;
    }
};
