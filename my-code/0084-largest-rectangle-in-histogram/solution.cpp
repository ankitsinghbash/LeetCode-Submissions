class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //Important for stack concept:
        int n = heights.size();
        vector<int> right(n);
        vector<int> left(n);

     
        stack<int> st;  //contain index of heights
        right[n-1] = n;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
                
                while(!st.empty() && heights[i]<=heights[st.top()]){
                    st.pop();
                }
                if(st.empty()){
                    right[i] = n;
                }
                else{
                    right[i] = st.top();
                }
                st.push(i);
        }



         stack<int> st1;
         st1.push(0);
         left[0]=-1;

         for(int i=1;i<n;i++){
            while(!st1.empty() && heights[i]<=heights[st1.top()]){
                      st1.pop();
            }
            if(st1.empty()){
                left[i]= -1;
            }
            else{
                left[i] = st1.top();
            }
            st1.push(i);
         }


         int maxx=0;
         for(int i=0;i<n;i++){
            int width = right[i]-left[i]-1;
            int area = width*heights[i];
            if(area>maxx) maxx = area;
         }
         return maxx;
    }
};
