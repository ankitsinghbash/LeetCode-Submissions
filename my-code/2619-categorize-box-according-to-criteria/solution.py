class Solution(object):
    def categorizeBox(self, l, w, h, m):
        v=l*w*h
        bull=0
        heavy=0
        if(l>=10000 or w>=10000 or h>=10000 or v>=1000000000):
            bull=1
        if(m>=100):
            heavy=1
        if(bull and heavy):
            return "Both"
        if(bull==0 and heavy==0):
            return "Neither"
        if(bull):
            return "Bulky"
        if(heavy):
            return "Heavy"
        """
        :type length: int
        :type width: int
        :type height: int
        :type mass: int
        :rtype: str
        """
        
