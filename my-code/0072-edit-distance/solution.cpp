//Define 2D dp without size:
struct PairHash {
    template <typename T1, typename T2>
    size_t operator()(const pair<T1, T2> &p)
    const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};
 

class Solution {
public:
//All are same:
//72. Edit Distance
//712. Minimum ASCII Delete Sum for Two Strings
//583. Delete Operation for Two Strings   

   // unordered_map<pair<int,int>,int,PairHash> dp; //C++ does not have a pair has so make's it template:
    //using #include <utility>
    int solve(const std::string& word1, const std::string& word2, int idx1, int idx2,unordered_map<pair<int,int>,int,PairHash> &dp) {
        if (idx1 >= word1.size()) {
            // Get the rest of word2
            return word2.size() - idx2;
        }
        if (idx2 >= word2.size()) {
            return word1.size() - idx1;
        }

        if (dp.find({ idx1, idx2 }) != dp.end()) {
            return dp[{ idx1, idx2 }];
        }

        if (word1[idx1] == word2[idx2]) {
            return dp[{ idx1, idx2 }] = solve(word1, word2, idx1 + 1, idx2 + 1,dp);
        }

        int op1 = solve(word1, word2, idx1 + 1, idx2 + 1,dp); // Replace
        int op2 = solve(word1, word2, idx1 + 1, idx2,dp);     // Delete
        int op3 = solve(word1, word2, idx1, idx2 + 1,dp);     // Insert (or delete from word2)

        return dp[{ idx1, idx2 }] = std::min({ op1, op2, op3 }) + 1;
    }

   

    int minDistance(string word1, string word2) {
        //two approach:
      //  vector<vector<int>> dp(501,vector<int>(501,-1));
      unordered_map<pair<int,int>,int,PairHash> dp;
        return solve(word1,word2,0,0,dp);
    }
};
