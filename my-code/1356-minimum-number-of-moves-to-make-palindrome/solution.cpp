class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        
        int ans=0;
        int lt=0;
        int rt=s.size()-1;
        while(lt<rt)   //not required to make equal because for palindromic string lt<rt bhi kar dega:
        {
            //make new pointer which real swap the real value;
            int l=lt,r=rt;
            while(s.at(l)!=s.at(r))    
            {
                r--;      //let s=aabb   //here s[0]!=s[3] -->>decrease karo r ko upto a na mil jaay:
                           //we find a at s[1]=a; so s[0] and s[1] both are equal to a;
            }
            
            //case of swaping;
            //special case:
                                  //let's take string s = abb;
                                 //l->to a and r->to second b;
                                 //now fix a and find a from r=second wale b se as above;
                              //r ko decrease karte karte first a pe jab pauchuga then
                              //Initial wale a in r wale a hoge means;
                               //pointer l and r both at same wale a pe aa jayage:
            if(l==r)
            {
                swap(s.at(r),s.at(r+1));
                ans++;   //count number of swap:
                continue;
            }
            else
            {
                //it's normally swap the value and count the value and store in ans count:
                //this is the case let;s
                //string s=aabb; decrease r and find fisrt a from last;
                //s[l]->fisrt wala a,and s[r]->second wala a;
                while(r<rt)
                {
                    swap(s.at(r),s.at(r+1));
                    ans++;
                    r++;
                }
            }
            lt++;
            rt--;
        }
        return ans;
    }
};
