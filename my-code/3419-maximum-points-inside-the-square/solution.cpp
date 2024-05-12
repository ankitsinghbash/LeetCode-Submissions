class Solution {
public:
    int isvalid(vector<vector<int>>&points,string s,int mid){

         int a = abs(mid);
         int b = -abs(mid);
        //mid is the longest length of square is possible:
           int cnt=0;
           unordered_set<char> st;
           for(int i=0;i<points.size();i++){
            int x = points[i][0];
            int y = points[i][1];
            if(x>=b && x<=a && y>=b && y<=a){
                 if(st.find(s[i])==st.end()){
                    st.insert(s[i]);
                    cnt++;
                 }
                 else{
                    //means already present in set:
                    return -1;  //not valid case:
                 }
            }

           }
           return cnt;
    }
    
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
           int low=0;
           int high = 1e9;
           int maxx = INT_MIN;
           while(low<=high){
             int mid = low+(high-low)/2;
             int x = isvalid(points,s,mid);
             if(x==-1){
                high = mid-1;
             }
             else{
                low=mid+1;
                maxx = max(maxx,x);
             }
           }
           return maxx;
    }
};
