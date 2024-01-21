class Solution {
public:
    int minimumPushes(string word) {
        int len = word.size();
        if(len<=8){
            return len;
        }
        else if(len>8 && len<=16){
            int rest = len-8;
            int cnt=0;
            cnt+=rest*2+8;
            return cnt;
        }
        else if(len>16 && len<=24){
            int cnt=0;
            int rest = len-8;
            cnt+=8;
            int newrest = rest-8;
            cnt+=8*2;
            cnt+=newrest*3;
            return cnt;
        }
        else{
            int cnt=0;
            int rest = len-8;
            cnt+=8;
            int newrest = rest-8;
            cnt+=8*2;
            int newwrest=newrest-8;
            cnt+=8*3;
            cnt+=newwrest*4;
            return cnt;
        }
        
    }
};
