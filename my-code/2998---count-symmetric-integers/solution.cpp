class Solution {
public:
    bool check(string str){
        int n = str.size();
        int first_half = n/2;
        int start_sum=0;
        for(int i=0;i<n/2;i++){
            int value = str[i]-'0';
            start_sum+=value;
        }
        
        int last_sum=0;
        for(int i=n/2;i<n;i++){
            int value = str[i]-'0';
            last_sum+=value;
        }
        
        return start_sum==last_sum;
        
        
        
        
    }
    
    
    int countSymmetricIntegers(int low, int high) {
        int cnt=0;
        while(low<=high){
            string str = to_string(low);
            int n = str.size();
            if(n%2==0){
                int half = str.size()/2;
                if(check(str)==true){
                    cnt++;
                }
            }
            low++;
        }
        return cnt;
    }
};
