class Solution {
public:
    int trap(vector<int>& height) {
        //Check GfG List of same problem explain with good example:
        int n=height.size();
        
        vector<int> L;
        vector<int> R;
        int data=0;  //just a varible for compair a positive value:
        for(int i=0;i<n;i++)
        {
            if(height[i]>data)
            {
                data=height[i];
            }
            L.push_back(data);
        }
        
        data=0;   //just a variable for compair the positive value:
        for(int i=n-1;i>=0;i--)
        {
            if(height[i]>data)
            {
                data=height[i];
            }
            R.push_back(data);
        }
        
        //reverse the R for find the correct R:
        reverse(R.begin(),R.end());
        
        int total_water=0;
        
        //formula total_water=min(L[i],R[i])-heigh[i];  Use in each iteration:
        for(int i=0;i<n;i++)
        {
            int mini=min(L[i],R[i]);
            total_water+=mini-height[i];
        }
        return total_water;
    }
};
