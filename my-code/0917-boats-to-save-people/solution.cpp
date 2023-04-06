class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int start = 0;
        int last = people.size()-1;
        int cnt = 0;
        while(start<=last){
            int weight=people[start]+people[last];
            if(weight<=limit){
                start+=1;
            }
            cnt++;
            last--;
            // if(weight>limit){
            //     last--;
            //     cnt++;
            // }
            // else{
            //     cnt++;
            //     start++;
            //     last--;
            // }
        }
        return cnt;
    }
};
