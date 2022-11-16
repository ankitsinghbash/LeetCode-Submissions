class Solution {
public:

  bool solve(string str1,string newstr)
  {
      for(int i=0;i<str1.size();i++)
      {
          char ch1=str1.at(i);
          char ch2 =newstr.at(i);
          if(ch1!=ch2){
              return false;
          }
                    
      }
      return true;
  }

    int numOfPairs(vector<string>& nums, string target) {
        int counter=0;
        int n = target.size();
        for(int i=1;i<nums.size();i++)
        {
            int gvsize  = nums[i].size();
            string str1=nums[i];
            if(n>gvsize)
            {
                int restsize  = n-gvsize;
                for(int j=0;j<i;j++)
                {
                    if(nums[j].size()==restsize)
                    {
                        string str2 = nums[j];
                        string newstr = str2+str1;
                        string secondstr = str1+str2;
                        if(newstr.compare(target)==0)
                        {
                            counter++;
                        }
                        if(secondstr.compare(target)==0)
                        {
                         counter++;
                        }
                    } 
                }
            }
        }
        return counter;
    }
};
