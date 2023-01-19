class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        //deque take less time:
        deque<int> d;
        d.assign(nums.begin(),nums.end());
        for(int i=1;i<=k;i++){
            int val = d.back();
            d.pop_back();
            d.push_front(val);
        }
        nums.clear();
        for(auto it=d.begin();it!=d.end();++it){
            nums.push_back(*it);
        }
    }
};
