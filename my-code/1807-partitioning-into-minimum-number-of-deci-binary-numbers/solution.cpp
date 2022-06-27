class Solution {
public:
    int minPartitions(string n) {
        int max_initial = 0;
        for(int i=0;i<n.size();i++)
        {
            max_initial=max(max_initial,n[i]-'0');
        }
        return max_initial;
    }
};
