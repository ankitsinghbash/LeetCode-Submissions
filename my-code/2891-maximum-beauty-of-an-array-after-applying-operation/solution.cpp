class Solution { 
public: 
    int maximumBeauty(vector<int>& nums, int k) { 
        map<int,int> freq; 
        for(int i=0;i<nums.size();i++) 
        { 
            freq[nums[i]-k]++; 
            freq[nums[i]+k+1]--; 
        } 
        
        int cnt = 0; 
        int answer = 0; 
        for(auto x:freq) 
        { 
            cnt+= x.second; 
            answer=max(answer,cnt); 
        } 
        return answer; 
    } 
};
