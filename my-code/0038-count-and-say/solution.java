class Solution {
    public String countAndSay(int n) {
        
        if(n==1)
        {
            return "1";
        }
        String s  = countAndSay(n-1);
        String str="";
        int counter=0;
        for(int i=0;i<s.length();i++)
        {
            counter++;
            if(i==s.length()-1||s.charAt(i)!=s.charAt(i+1))
            {
                str=str+counter+s.charAt(i);
                counter=0;
            }
        }
        return str;
    }
}
