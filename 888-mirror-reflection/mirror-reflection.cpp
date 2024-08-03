class Solution {
public:
    int mirrorReflection(int p, int q) {
        int a=1, b=1;
        //a*p = b*q , eo=0, oo=1, oe=2
        while(a*p!=b*q){
            if(a*p<b*q) a++; 
            else b++;
        }
        if(a%2==0 && b%2==1) return 0;
        if(a%2==1 && b%2==1) return 1;
        else return 2;
    }
};