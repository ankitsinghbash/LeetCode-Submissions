class Solution {
public:
    int minBitFlips(int start, int goal) {
           bitset<32> first = bitset<32>(start);
           bitset<32> second = bitset<32>(goal);
           int cnt=0;
           for(int i=31;i>=0;i--){
               if(first[i]!=second[i]) cnt++;
           }
           return cnt;
    }
};
