class Solution {
public:
    vector<int> arr;
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n=capacity.size();
        for(int i=0;i<n;i++){
            int val = capacity[i]-rocks[i];
            arr.push_back(val);
        }
   
       sort(arr.begin(),arr.end());
    //    int flag=0;
    //    for(int i=0;i<arr.size();i++){
    //        if(arr[i]==0){
    //            flag++;
    //        }
    //    }
    //    for(auto x:arr){
    //        cout<<x<<" ,";
    //    }

       int sum=0;
       int counter=0;
       for(int i=0;i<n;i++){
           sum+=arr[i];
           counter++;
           if(sum>additionalRocks){
               break;
           }
       }
       if(sum<=additionalRocks){
           return n;

       }
       return counter-1;
       


    }
};
