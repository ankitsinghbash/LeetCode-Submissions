class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int counter=1;
        int i=1;
        sort(arr.begin(),arr.end());
        vector<int> ans;
        while(i<arr.size()){
            if(arr[i]==arr[i-1]){
               counter++; 
            }
            else{
                ans.push_back(counter);
                counter=0;
                counter=1;
            }
            i++;
        }
        ans.push_back(counter);
  
        sort(ans.begin(),ans.end());

        int j=1;
        while(j<ans.size()){
            if(ans[j]==ans[j-1]){
                return false;
            }
            j++;
        }
        return true;

      
    }
};
