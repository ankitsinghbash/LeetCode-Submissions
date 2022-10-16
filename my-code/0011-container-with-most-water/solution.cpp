class Solution {
public:
    int maxArea(vector<int>& height) {
       //area of histogram me next greater element:
       int i=0;
       int j=height.size()-1;
       int ans = INT_MIN;
       while(i<j)
       {
          int maxarea = (j-i)*min(height[i],height[j]);
          if(maxarea>ans)
          {
              ans=maxarea;
          }
          if(height[i]>height[j])
          {
              //mughe max area chayia hence if height[i]>height[j];
              j--;
          }
          else{
              i++;
          }
       }
       return ans;
    }
};



/*/
//brute force:
 int maxstore = INT_MIN;
        while(height.size()!=1)
        {
        
        int idxzero=0;
        int idxlast=height.size()-1;
        int first=height[idxzero]; 
        int last=height[idxlast];
        int minimum;
        if(first>last)
        {
            minimum=last;
        }
        else{
            minimum=first;
        }

        int gaps=idxlast;           //gaps == indexing:

        
      
        if(minimum*gaps>maxstore)
        {
           maxstore=minimum*gaps;
        }
        
        //delete the minimum element of the idex:
        if(height[0]==minimum)
        {
            //delete this:
            height.erase(height.begin()+0);
        }
        else
        {
            //delete the last = height[height.size()-1];
            height.erase(height.begin()+idxlast);
        }

        }
        return maxstore;

*/
