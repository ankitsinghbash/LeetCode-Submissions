class Solution {
public:
    bool checkStrings(string s1, string s2) {
     unordered_map<char,int> mp1_even;
    unordered_map<char,int> mp1_odd;
    unordered_map<char,int> mp2_even;
    unordered_map<char,int> mp2_odd;

    for (int i = 0; i < s1.length(); i++) {
        if (i % 2 == 0) {
            mp1_even[s1[i]]++;
            mp2_even[s2[i]]++;
        } else {
            mp1_odd[s1[i]]++;
            mp2_odd[s2[i]]++;
        }
    }

    return (mp1_even == mp2_even && mp1_odd == mp2_odd);
    }
};
