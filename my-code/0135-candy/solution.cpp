class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int n=ratings.size();
        vector<int> left(n,1);   //make a vector of size n+1 because we start add value from i=1 and take all value defalut as 1 for 1 candy minimum to each children;
        vector<int> right(n,1);
        
        
        //Now traversal fron i=1;
       for(int i=1;i<n;i++)
       {
            if(ratings[i]>ratings[i-1])
            {
            left[i]=left[i-1]+1;
            }
        }
        
        //index problem nahi karega left right ka because we already given value 1 int the initial case:
        //we just only increase the value +1 if the condition got true;
         for(int j=n-2;j>=0;j--){
            if(ratings[j]>ratings[j+1])
            {
                right[j]=right[j+1]+1;
            }
        }
        
        
       int sum=0;
        for(int i=0;i<n;i++){
            sum+=max(left[i],right[i]);
        }
        return sum;
        
        
        
        
    }
};
