class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        //optimal approch:
        unordered_map<int,int> mp;
        int n = hours.size();
        long long int ans=0;
        for(int i=0;i<n;i++){
            int value = hours[i]%24;
            int required = (24-value)%24;
            ans+=mp[required];
            mp[value]++;
         
        }
        return ans;
        
    }
};
//: hours = [12,12,30,24,24]

//12--2
//18--1
//24--2

