class Solution {
public:
    int minChanges(int n, int k) {
        //binary of 14=1110
        //binary of 13=	1101
        
        //need to convert 14 and 13 to binary ;
        string nums = bitset<32>(n).to_string();
        string kvalue = bitset<32>(k).to_string();
        
        
        int cnt=0;
        //iterative over 32 bits:
        for(int i=0;i<32;i++){
            if(nums[i]=='0' && kvalue[i]=='1'){
                return -1;
            }
            else if(nums[i]=='1' && kvalue[i]=='0'){
                cnt++;
            }
        }
        return cnt;
        
        
    }
};
