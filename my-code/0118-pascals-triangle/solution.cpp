class Solution {
public:
   vector<vector<int>> ans;
    vector<vector<int>> generate(int numRows) {
        int time = numRows;
        if(time==1){
            return {{1}};
        }
        else if(time==2){
            return {{1},{1,1}};
        }

        int TIME=time-2;
        ans.push_back({1}); 
        ans.push_back({1,1});
        vector<int> store = {1,1};
        while(TIME--){
            vector<int> temp;
            temp.push_back(store[0]);
            for(int i=1;i<store.size();i++){
                int value = store[i]+store[i-1];
                temp.push_back(value);
            }
            temp.push_back(store[store.size()-1]);
            ans.push_back(temp);
            store = temp;
            temp.clear();
        }
        return ans;
    }
};
