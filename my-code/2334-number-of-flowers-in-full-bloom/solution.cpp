class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n =  flowers.size();
        vector<int> first(n);
        vector<int> second(n);

        for(int i=0;i<flowers.size();i++){
            first[i] = flowers[i][0];
            second[i] = flowers[i][1];
        }
        sort(first.begin(),first.end());
        sort(second.begin(),second.end());

       
        vector<int> ans;
        for(int i=0;i<people.size();i++){
            int val = people[i];
            int idx1 = upper_bound(first.begin(),first.end(),val)-first.begin(); //if found give the upper index if not found give the insertion point:
            int idx2 = lower_bound(second.begin(),second.end(),val)-second.begin(); //if found give index if not found five the insertion point
            int cnt = idx1-idx2;
            ans.push_back(cnt);
        }
        
        return ans;

    }
};
