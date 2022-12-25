class Solution
{
public:
    vector<int> ans;
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
    {
        //nums->1,2,4,5 and queries->3,10,21;

        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++)
            nums[i] += nums[i - 1];    //prefix sum:

        for (auto x: queries)
        {
            int k;
            for (k = 0; k < nums.size(); k++)  
            {
                if (x<nums[k])
                    break;
            }
            ans.push_back(k);  //it handle the case 21 k comeout from loop and and give maxvalue k=nums.size();
        }
        return ans;
    }
};
