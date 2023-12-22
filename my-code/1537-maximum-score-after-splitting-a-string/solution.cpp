class Solution {
public:
    int data_val1(string &str){
        int counter=0;
        for(int i=0;i<str.size();i++){
            if(str[i]=='1'){
                counter++;
            }
        }
        return counter;
    }

     int data_val0(string &str){
         int counter=0;
         for(int i=0;i<str.size();i++){
             if(str[i]=='0'){
                 counter++;
             }
         }
         return counter;
     }

    int maxScore(string s) {
        int maxx = INT_MIN;
        for(int i=0;i<s.size()-1;i++){
            string s1 = s.substr(0,i+1);
            string s2 = s.substr(i+1);
            int val1 = data_val0(s1);
            int val2 = data_val1(s2);
            maxx = max(maxx,val1+val2);
        }
        return maxx;
    }
};
