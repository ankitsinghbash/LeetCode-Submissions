class Solution {
public:
   struct cmp{
       bool operator()(pair<int,int> &a,pair<int,int> &b){
           if(a.second == b.second){
                return a.first<b.first;
           }
           return a.second<b.second;
       }
   };

    int count_one(int nums){
        int counter=0;
        while(nums!=0){
            int rem = nums%2;
            if(rem==1){
                counter++;
            }
            nums=nums/2;
        }
        return counter;
    }

    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> ans;
        for(int i=0;i<arr.size();i++){
            int val = arr[i];
            int cnt_1 = count_one(val);
            ans.push_back({val,cnt_1});
        }


        sort(ans.begin(),ans.end(),cmp());


        vector<int> store;
        for(int i=0;i<ans.size();i++){
            pair<int,int> P = ans[i];
            store.push_back(P.first);
        }
        return store;
    }
};
