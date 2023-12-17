class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        char prev = '\0';
        int curr = 0;
        int prev_need = 0;
        for (int i = 0; i < colors.size(); i++) {
            char curr_color = colors[i];
            if (prev == '\0' || prev != curr_color) {
                curr += neededTime[i];
                prev = curr_color;
                prev_need = neededTime[i];
            } else {
                // Equal colors
                int curr_need = neededTime[i];
                if (curr_need > prev_need) {
                    curr -= prev_need;
                    curr += curr_need;
                    prev_need = curr_need;
                }
            }
        }
        auto total = accumulate(neededTime.begin(),neededTime.end(),0);
        return (total-curr);
    }
};
