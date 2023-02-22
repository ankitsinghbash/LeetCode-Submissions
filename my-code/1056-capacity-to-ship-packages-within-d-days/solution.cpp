class Solution {
public:
   
    int solve(vector<int> &arr,int cap){
        int sum=0;
        int  cnt=0;
        for(auto &x : arr){
            if(x>cap){
                return INT_MAX;
            }
            if(sum<=cap){
                sum+=x;
            }
            if(sum>cap){
                sum=0;
                sum=x;
                cnt++;
            }
        }
        if(sum<=cap){
            cnt++;
        }
        return cnt;
    }
  

    int shipWithinDays(vector<int>& arr, int D) {
        int low=1;
        int high=INT_MAX;
        while(low<high){
            int mid = low+(high-low)/2;
            int day = solve(arr,mid);
            if(day<=D){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};







// class Solution {
   
//      public static int solve(int cap,int arr[])
//     {
//         int count=1;
//         int sum=0;
//         for(int a:arr)
//         {
//             if(a>cap)
//             return Integer.MAX_VALUE;
            
//             if(sum+a<=cap)
//             {
//                 sum+=a;
//             }
//             else
//             {
//                 count++;
//                 sum=a;
//             }
//         }
//         return count;
//     }


//     public int shipWithinDays(int[] arr, int D) {
         
//         int start=1, end=(int)1e9;
//         while(start<end)
//         {
//             int mid=start+(end-start)/2;
//             int days=solve(mid,arr);
//             if(days<=D)
//             end=mid;
//             else
//             start=mid+1;
//         }
//         return start;

//     }
// }
