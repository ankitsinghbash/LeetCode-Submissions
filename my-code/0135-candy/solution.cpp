class Solution {
public:
    //dry run for [5,3,4,5,6,3,2] at val(6) we have two option left se 3 and right se 2 so i taken max because left ke side asi 3 value rahe hogi jiske lyia candy increase kyia and right me 2 rahi hogi so for optimally we take the left side candy 3 then added 1 for val(6) at 6 it become 4:
    //so basically we taken two option at each point ki left and right me maximum kon thi:
    //That why this algorithm works:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n,1);
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                left[i] = left[i-1]+1;
            }
        }
        vector<int> right(n,1);
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                right[i]=right[i+1]+1;
            }
        }
        int sum=0;
        for(int i=0;i<n;i++){
            int value = max(left[i],right[i]);
            sum+=value;
        }
        return sum;
    }
};
