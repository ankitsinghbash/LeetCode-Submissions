class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        //intitution chayia ;
        //prefix sum:
        long long int sum=0;
        long long int even=0,odd=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum%2==0){
                even++;
            }
            else{
                odd++;
            }
        }
        //intution: number of odd to means utna time odd hai subarray:
        //number of even mean rest every odd-even==odd means rest every odd given subtract with even given an odd --> odd*even;
        return odd+(odd*even)%1000000007;
       
    }
};
