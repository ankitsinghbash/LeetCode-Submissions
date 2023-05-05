class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int cnt = 0;
        int mini = INT_MAX;
        for(int i=0;i<k;i++){
            if(blocks[i]=='W'){
                cnt++;
            }
        }
        mini=min(mini,cnt);

        for(int i=k;i<blocks.size();i++){
            if(blocks[i]=='W'){
                cnt++;
            }
            if(blocks[i-k]=='W'){
                cnt--;
            }
            mini=min(mini,cnt);
        }
        return mini;
        
    }
};
