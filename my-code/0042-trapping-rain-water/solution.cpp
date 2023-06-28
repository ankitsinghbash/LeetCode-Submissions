class Solution {
public:
    int trap(vector<int>& height) {
        //O(n):
        int n = height.size();
        vector<int> L(n);
        int data1=0;
        for(int i=0;i<n;i++){
            if(height[i]>data1){
                data1=height[i];
            }
            L[i]=data1;
        }

  
        vector<int> R(n);
        int j=0;
        int data2=0;
        for(int i=n-1;i>=0;i--){
            if(height[i]>data2){
                data2=height[i];
            }
            R.push_back(data2);
        }

        reverse(R.begin(),R.end());

        int water = 0;
        for(int i=0;i<n;i++){
            int value = min(L[i],R[i])-height[i];
            water+=value;
        }
        return water;

    }
};
