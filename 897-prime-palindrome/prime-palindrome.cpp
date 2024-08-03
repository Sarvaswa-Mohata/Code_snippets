class Solution {
public:
        bool isPrime(long long int N)
    {

        // If the number is less than or equal to 1,
        // it is not prime
        if (N <= 1) {
            return false;
        }

        // If the number is 2 or 3, it is prime
        if (N <= 3) {
            return true;
        }

        // If the number is divisible by 2 or 3,
        // it is not prime
        if (N % 2 == 0 || N % 3 == 0) {
            return false;
        }

        // Check for divisors from 5
        // to the square root of N
        for (int i = 5; i * i <= N; i += 6) {

            // If N is divisible by i or (i + 2),
            // it is not prime
            if (N % i == 0 || N % (i + 2) == 0) {
                return false;
            }
        }

        // If no divisors are found, it is prime
        return true;
    }

    void func(vector<string>& v){
        for(int i=1;i<=3e4;i++){
            string str = to_string(i);
            int n=str.size();
            //10 -> 101, 1001
            if(str.size()==1) v.push_back(str);
            string s1=str, s2=str;
            if(n>=2){
                for(int i=n-2;i>=0;i--){
                    s1+=str[i];
                }
                v.push_back(s1);
            }
            for(int i=n-1;i>=0;i--){
                s2+=str[i];
            }
            v.push_back(s2);
        }
    }
    long long int primePalindrome(int n) {
        vector<string> v;
        vector<long long int> v_cpy;
        func(v);
        for(auto it:v){
            long long int jt=stoll(it);
            if(isPrime(jt)) v_cpy.push_back(jt);
        }
        sort(v_cpy.begin(),v_cpy.end());
        long long int ans = *lower_bound(v_cpy.begin(), v_cpy.end(), n);
        return ans;
    }
};