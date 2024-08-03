class Solution {
public:
    int addDigits(int num) {
        int sum=0;
        while(true){
            if(num==0){
                if(sum<=9) return sum;
                num=sum;
                sum=0;
            }
            sum+=num%10;
            num/=10;
        }
        return sum;
    }
};