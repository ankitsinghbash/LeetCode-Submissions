class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int rb[n];
        int lb[n];

        st.push(n-1);   //push indexing:
        rb[n-1]=n;
        for(int i=n-2;i>=0;i--){
            while(!st.empty()>0 && heights[i] <= heights[st.top()]){
                st.pop();
            }
            if(st.empty()){
                rb[i]=n;
            }
            else{
                rb[i]=st.top();
            }
            st.push(i);
        }

         stack<int> st2;
         st2.push(0);
         lb[0]=-1;
         for(int i=1;i<n;i++){
             while(!st2.empty() && heights[i]<=heights[st2.top()] ){
                 st2.pop();
             }
             if(st2.empty()){
                 lb[i]=-1;
             }
             else{
                 lb[i]=st2.top();
             }
             st2.push(i);
         }

  
        int maxarea=0;
        for(int i=0;i<n;i++){
            int width = rb[i]-lb[i]-1;
            int area = width*heights[i];
            maxarea=max(maxarea,area);
        }
        return maxarea;

    }
};
