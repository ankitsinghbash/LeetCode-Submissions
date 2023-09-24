class Solution {
public:
    typedef long long ll;
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        
        int n = maxHeights.size();
        
        int maxx=*max_element(maxHeights.begin(),maxHeights.end());
        
        ll result = 0;
        
        for (ll j=0;j<n;j++){
            ll total = 0;
            ll old = maxx;
            for (ll i=j;i<n;i++) {
                if (maxHeights[i]>=old){
                    total=total+old;
                }
                else{
                    old=maxHeights[i];
                    total=total+maxHeights[i];
                }
            }
            old=maxx;
            for (int i=j-1;i>=0;i--){
                if (maxHeights[i]>=old) {
                    total=total+old;
                } 
                else {
                    old=maxHeights[i];
                    total=total+maxHeights[i];
                }
            }
            if(total>result){
                result=total;
            }
        }
        
        return result;  
    } 
};
