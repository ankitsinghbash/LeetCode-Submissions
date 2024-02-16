class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        vector<int> store;
        int cnt=1;
        for(int i=1;i<arr.size();i++){
              if(arr[i]==arr[i-1]){
                  cnt++;
              }
              if(arr[i]!=arr[i-1]){
                  store.push_back(cnt);
                  cnt=1;
              }
        }
        store.push_back(cnt);
        sort(store.begin(),store.end());

        int left=0;
        int currsum=0;
        while(left<store.size()){
               currsum+=store[left];
               if(currsum>k){
                   break;
               }
               left++;
        }
        int len = store.size()-left;
        return len;
     
    } //// [1,2]
};
