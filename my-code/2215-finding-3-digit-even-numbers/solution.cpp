class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> s;
        int size = digits.size();
        for (int i = 0; i < size; i++) 
        {
            if (digits[i] % 2 == 0) 
            {
                int s1 = digits[i];
                for (int j = 0; j < size; j++) 
                {
                    if (j == i)
                        continue;
                    int s2 = digits[j] * 10 + s1;
                    for (int k = 0; k < size; k++) 
                    {
                        if (k == i or k == j or digits[k] == 0)
                            continue;
                        int s3 = digits[k] * 100 + s2;
                        s.insert(s3);
                    }
                }
            }
        }
        vector<int> res;
        for (int str : s) {
            res.emplace_back(str);
        } 
        return res;
    }
};
