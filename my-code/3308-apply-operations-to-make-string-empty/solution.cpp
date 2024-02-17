class Solution {
public:
    string lastNonEmptyString(string s) {
        unordered_map<char,int> mp;
        int maxx=0;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            maxx = max(maxx,mp[s[i]]);
        }

        string ans="";
        for(int i=s.size()-1;i>=0;i--){
            char ch = s.at(i);
            if(mp[ch]==maxx){
                mp[ch]=0;
               ans=ch+ans;
            }
        }
        return ans;

    }
};


//aaaaab
//a---4-1=aaa
//b---1-1=0



//aaabcbbca:
//a--4-2=2-1=1     a bbb
//b--3-2=1-1=0
//c--2-2=0   0


//4
