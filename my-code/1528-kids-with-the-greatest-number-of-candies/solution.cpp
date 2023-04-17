class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxx = 0;
        for(int i=0;i<candies.size();i++){
            maxx=max(maxx,candies[i]);
        }
        
        vector<bool> ans;
        for(int i=0;i<candies.size();i++){
            if(candies[i]+extraCandies>=maxx){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};
