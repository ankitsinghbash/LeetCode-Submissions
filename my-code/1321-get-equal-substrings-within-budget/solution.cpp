class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
          //Greedy solution:
          int n = s.size();
          vector<int> arr(n);
          for(int i=0;i<n;i++){
              arr[i] = abs(s[i]-t[i]);
          }

            
          int maxx= 0;
          for(int i=0;i<n;i++){
              int len=0;
              int j =i;
              int current_cost = 0;
              while(j>=0&&current_cost+arr[j]<=maxCost){
                    current_cost+=arr[j];
                    len++;
                    j--;
              }
              maxx = max(maxx,len);
          }
          return maxx;

    }
};
