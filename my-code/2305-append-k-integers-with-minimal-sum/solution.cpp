class Solution {
public:
  
    long long int get_sum(long long int  cnt,long long int start){
        return (cnt*((2*start)+(cnt-1)))/2;   //sum of first n number minus sum of first n-2 number  --> n*(n+1)/2 - (n-2)((n-2)+1)/2:
    }

    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long sum=0;
        int start=1;
        for(int i=0;i<nums.size();++i){
            int X = nums[i]-start;
            if(X>=0){
                if(k<=X){
                   X=k;
                   k=0;
                }
                if(k>X){
                    k-=X;
                }
                sum+=get_sum(X,start);
                start=nums[i]+1;
            }
            if(k==0){
                break;
            }
        }
        if(k!=0){
            sum+=get_sum(k,start);
        }
        return sum;
    }
};
