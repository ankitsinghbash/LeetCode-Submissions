class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int arr[n+1];
        arr[0]=0;
        int sum=0;
        for(int i=0;i<gain.size();i++){
            sum+=gain[i];
            cout<<sum<<endl;
            arr[i+1]=sum;
        }
 
        int value = *max_element(arr,arr+n+1);
        return value;

    }
};
