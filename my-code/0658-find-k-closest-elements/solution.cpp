class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
         
         int sum=0;  //diff sum; 
         vector<int> real;
         for(int i=0;i<k;i++){
             real.push_back(arr[i]);
             int val = abs(arr[i]-k);
             sum+=val;
         }

         int n = arr.size();
         int j=k;

         while(j<n){
            int val = abs(arr[j]-x);
            int newsum = sum+val-abs((arr[j-k]-x));
            if(newsum<sum){
                real.push_back(arr[j]);
                real.erase(real.begin());
                sum=newsum;
            }
             j++;
         }
         return real;

    }
};
