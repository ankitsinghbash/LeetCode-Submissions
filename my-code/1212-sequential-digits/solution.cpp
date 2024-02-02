#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        queue<int> qu;

        for (int i = 1; i <= 9; i++) {
            qu.push(i);
        }

        while (!qu.empty()) {
            int nums = qu.front();
            qu.pop();

            if (nums <= high && nums >= low) {
                ans.push_back(nums);
            }

            int lastDigit = nums % 10;

            if (lastDigit < 9) {
                qu.push(nums * 10 + lastDigit + 1);
            }
        }

        return ans;
    }
};

