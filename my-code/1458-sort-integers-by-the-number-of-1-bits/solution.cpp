#pragma GCC optimize("O3")
#pragma GCC target("popcnt")

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
        while(nums!=0){   //log2(N)
           counter+=(nums&1);
           nums = nums>>1;
        }
        return counter;
    }

    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> ans;
        for(int i=0;i<arr.size();i++){
            int val = arr[i];
            int cnt_1 = __builtin_popcount(val); //builtin_popcount() give number of 1's in Binary representation of num:
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
