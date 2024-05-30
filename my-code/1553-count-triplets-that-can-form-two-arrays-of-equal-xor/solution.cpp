class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        
       
       vector<int> prefixXOR(n);
       int xor_value = 0;
       for(int i=0;i<n;i++){
            xor_value = xor_value^arr[i];
            prefixXOR[i] = xor_value;
       }
        
        for (int i=0;i<n-1;++i){
            for (int k=i+1;k<n;++k){
                if(i==0){
                    int value = prefixXOR[k];
                    if(value==0){
                       ans+=(k-i);
                    }
                }
                else{
                     int  value=prefixXOR[k]-prefixXOR[i-1];
                     if(value==0){
                      ans+=(k-i);
                  }
                }
            }
        }
        return ans;
    }
};

