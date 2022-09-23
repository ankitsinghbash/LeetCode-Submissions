class Solution {
public:
    vector<int> plusOne(vector<int>& d) {
        
        //best solution:
        int n=d.size();
        int c=1;  //take c is a number in first time;
        for(int i=n-1;i>=0;i--)
        {
            int last=d[i]+c;  //c is not carry it;s a numbe=1 in fist time;
            //Now i have two option fisrt->last=10, or last= one digit number;
            if(last==10) //last me only +1 karne hai to 10 hi hoge nahi to last>10
            {
                d[i]=0;
                c=1;
            }
            else
            {
                 d[i]=last;
                 c=0;
            }
        }
         if(c==1)    //case for [9]
             d.insert(d.begin(),1); 
        return d;
        
       
        
    }
};
