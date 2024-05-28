class Solution {
public:

    //how to find that ok there that student may late 3 consecutive days:
    int dp[100001][2][3];
    int const mod = 1e9+7;
    int solve(int cnt_P,int cnt_A,int cnt_L,int late_days,int days){
       
       if(late_days>2 || cnt_A>1){
        return 0;
       }

       if(days==0){
        return 1;
       }

       if(dp[days][cnt_A][late_days]!=-1){
        return dp[days][cnt_A][late_days];
       }



       int cnt=0;
       cnt=((cnt%mod+solve(cnt_P+1,cnt_A,cnt_L,0,days-1)%mod)%mod);
       cnt=((cnt%mod+solve(cnt_P,cnt_A+1,cnt_L,0,days-1)%mod)%mod);
       cnt=((cnt%mod+solve(cnt_P,cnt_A,cnt_L+1,late_days+1,days-1)%mod)%mod);



       return  dp[days][cnt_A][late_days]=(cnt%mod)%mod;

    }
    int checkRecord(int n) {
         int days = n;
         memset(dp,-1,sizeof(dp));
         return solve(0,0,0,0,days);
    }
};



// class Solution {
// public:
//     bool condition_is_ok(string str){
//             int cnt_A=0;
//             for(int i=0;i<str.size();i++){
//                 if(str[i]=='A'){
//                     cnt_A++;
//                 }
//                 if(i+2<str.size() && str[i]=='L' && str[i+1]=='L' && str[i+2]=='L'){
//                     return false;
//                 }
//             }
//             if(cnt_A>1){
//                 return false;
//             }
//             return true;
//     }

//     const int mod = 1e9+7;
//     int solve(string str,int days){
       
//         if(days==0){
//             if(condition_is_ok(str)){
//             return 1;
//             }
//             return 0;
//         }

//         //there are three possible happen:
//         int cnt=0;
//         cnt+=((solve(str+'P',days-1)%mod)%mod);
//         cnt+=((solve(str+'A',days-1)%mod)%mod);
//         cnt+=((solve(str+'L',days-1)%mod)%mod);


//        return cnt%mod;

//     }

//     int checkRecord(int n) {
//         return solve("",n);
//     }
// };
