class Solution {
public:
    int minStoneSum(vector<int>& box, int k) {
      //  sort(box.begin(),box.end());
        priority_queue<int> qu;
        for(int i=0;i<box.size();i++){
            qu.push(box[i]);
        }

        while(k!=0)
        {
            int first = qu.top();
            qu.pop();
            int val = first/2;
            int ans = floor(val);
            int req = first - ans;
            qu.push(req);
            k--;
        }
       
        int sum=0;
        while(!qu.empty()){
            int val = qu.top();
            sum+=val;
            qu.pop();
        }
        return sum;
    }
};
