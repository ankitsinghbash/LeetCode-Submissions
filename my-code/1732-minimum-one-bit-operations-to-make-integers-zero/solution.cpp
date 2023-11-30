// 0th)-->000--->0
// 1th)-->0001-->1
// 2th)-->0011-->3
// 3th)-->0010-->2
// 4th)-->0110-->6
// 5th)-->0111-->7
// 6th)-->0101-->5
// 7th)-->0100-->4
// 8th)-->1100-->12
// 9th)-->1101-->13
// 10th)->1111-->15
// 11th)->1110-->14
// 12th)->1010-->10
// 13th)->1011-->11
// 14th)->1001-->9
// 15th)->1000-->8


class Solution {
public:
    int minimumOneBitOperations(int n) {


    //observation the two condition is nothing but say this is a gray code:
         if(n==0){
             return 0;
         }
   
        //advanced algo to find the ith gray number:
        int ans = n;
        ans = ans ^ (ans>>16);
        ans = ans ^ (ans>>8);
        ans = ans ^ (ans>>4);
        ans = ans ^ (ans>>2);
        ans = ans ^ (ans>>1);
        return ans;
        //tle:
        //   int i=1;
        //   while(true){
        //       int val = i ^ (i>> 1);
        //       if(val==n){
        //           break;
        //       }
        //       i++;
             
        //   }
        //   return i;
    }
};
