class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        
        if(arr.size()<3) return false;

        int left=0;
        int right=2;  //window size:
        int codd=0;
        for(int i=left;i<=right;i++)
        {
            if(arr[i]%2!=0) codd++;
        }
      
       if(codd==3)return true;

        while(right!=arr.size()-1)
        {
           
            right++;
            if(arr[right]%2!=0) codd++;
            left++;
            if(arr[left-1]%2!=0) codd--;
             if(codd==3) return true;
        }
        return false;
        

    }
};
