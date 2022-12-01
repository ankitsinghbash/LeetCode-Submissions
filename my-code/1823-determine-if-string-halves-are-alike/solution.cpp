class Solution {
public:
    bool halvesAreAlike(string str) {
        
    int n=str.size();
    int counter1=0;
    int i;
    for(i=0;i<n/2;i++)
    {
      char ch = str.at(i);
      if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='E'||ch=='I'||ch=='O'||ch=='U'){
        counter1++;
      }
    }
    
    int counter2=0;
    for(int j=i;j<n;j++)
    {
      char ch = str.at(j);
      if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='E'||ch=='I'||ch=='O'||ch=='U'){
        counter2++;
      }
      
    }
    if(counter1==counter2)
    {
       return true;
    }
    else
    {
       return false;
    }
  
     return 0;
    }
};
