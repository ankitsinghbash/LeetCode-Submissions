class Solution {
public:
    int maximum_possible_value(vector<int> &nums, int first, int second) {
        int n = nums.size();
        int last = n - first - second;
        int maxx = 0;
        
        for (int idx = 0; idx <= last; idx++) {
            // Calculate sum for the first subarray
            int curr_sum = 0;
            for (int i = idx; i < idx + first; i++) {
                curr_sum += nums[i];
            }

            // Calculate sum for the second subarray
            int second_sum = 0;
            for (int j = idx + first; j < idx + first + second; j++) {
                second_sum += nums[j];
            }

           
            int total = curr_sum + second_sum;
            maxx = max(maxx, total);

           
            for (int k = idx + first + second; k < n; k++) {
                second_sum += nums[k];
                second_sum -= nums[k - second]; // Remove the element that goes out of the second subarray
                total = curr_sum + second_sum;
                maxx = max(maxx, total);
            }
        }

        return maxx;
    }

    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int maxx = 0;

       
        int answer1 = maximum_possible_value(nums, firstLen, secondLen);
        int answer2 = maximum_possible_value(nums, secondLen, firstLen);
        maxx = max(answer1, answer2);

        return maxx;
    }
};

