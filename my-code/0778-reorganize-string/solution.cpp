class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        for (char x : s) {
            mp[x]++;
        }

        priority_queue<pair<int, char>> pq;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (it->second > (n + 1) / 2) {
                return "";
            }
            pq.push({it->second, it->first});
        }

        string ans = "";
        while (pq.size() >= 2) {
            pair<int, char> P1 = pq.top();
            pq.pop();
            pair<int, char> P2 = pq.top();
            pq.pop();
            ans += P1.second;
            ans += P2.second;
            P1.first--;
            P2.first--;
            if (P1.first > 0) {
                pq.push(P1);
            }
            if (P2.first > 0) {
                pq.push(P2);
            }
        }

        if (!pq.empty()) {
            ans += pq.top().second;
        }
        return ans;
    }
};

