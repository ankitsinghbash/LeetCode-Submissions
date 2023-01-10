class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        
        long long l = length;
        long long w= width;
        long long h = height;

        long long volume = l*w*h;

        bool bull=false;
        bool hv = false;
        if(length>=1e4||width>=1e4||height>=1e4||volume>=1e9){
            //bulky:
            bull=true;
        }
        if(mass>=100)
        {
            //heavy;
            hv=true;
        }
        if(bull==true&&hv==true){
            return "Both";
        }
        if(bull==true&&hv==false){
            return "Bulky";
        }
         if(hv==false&&bull==false){
            return "Neither";
        }
        if(bull==false||hv==true){
            return "Heavy";
        }
        return "";
      
    }
};
