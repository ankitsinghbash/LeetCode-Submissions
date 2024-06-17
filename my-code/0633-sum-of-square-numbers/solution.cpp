class Solution {
public:
    bool judgeSquareSum(int c) {
         //convert to target sum two pointer:
         long long int low=0;
         long long int high = sqrt(c);
         while(low<=high){
             long long int value = low*low+high*high;
             if(value==c){
                return true;
             }
             if(value<c){
                low++;
             }
             else{
                high--;
             }
         }
         return false;

    }
};

//0-1



//74=5*5+7*7
//74 = sqrt(8) = 64+9+1;


//1-2-3-4-5-6-7-8



//64+1=65<74
//64+4<74
//64+9<73
//64+16>74   
//16+49<74
//25+
