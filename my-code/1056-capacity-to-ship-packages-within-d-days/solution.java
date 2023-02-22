class Solution {
   
     public static int solve(int cap,int arr[])
    {
        int count=1;
        int sum=0;
        for(int a:arr)
        {
            if(a>cap)
            return Integer.MAX_VALUE;
            
            if(sum+a<=cap)
            {
                sum+=a;
            }
            else
            {
                count++;
                sum=a;
            }
        }
        return count;
    }


    public int shipWithinDays(int[] arr, int D) {
         
        int start=1, end=(int)1e9;
        while(start<end)
        {
            int mid=start+(end-start)/2;
            int days=solve(mid,arr);
            if(days<=D)
            end=mid;
            else
            start=mid+1;
        }
        return start;

    }
}
