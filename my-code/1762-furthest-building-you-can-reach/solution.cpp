class Solution {
public:
    //heap:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        int i = 0;
        priority_queue<int> pq;

        for (i = 0; i < n - 1; i++) {
            if (heights[i] >= heights[i+1]) {
                continue;
            }
            int diff = heights[i+1] - heights[i];
            if (diff <= bricks) {
                bricks -= diff;
                pq.push(diff);
            } else if (ladders > 0) {
                if (pq.size()) {
                    int x = pq.top();
                    if (x > diff) {
                        bricks += x;
                        pq.pop();
                        pq.push(diff);
                        bricks -= diff;
                    }
                }
                ladders--;
            } else {
                break;
            }
        }

        return i;
    }
};
