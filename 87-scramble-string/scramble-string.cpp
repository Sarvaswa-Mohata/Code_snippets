class Solution {
public:
    unordered_map<string, bool> dp;
    bool isScramble(string s1, string s2) {
        string key = s1+"."+s2;
        if(dp.contains(key)) return dp[key];

        if (s1 == s2) return dp[key] = true; // Base case: if the strings are equal
        if (s1.size() != s2.size()) return dp[key] = false; // Base case: different lengths cannot be scrambles

        string sorted_s1 = s1;
        string sorted_s2 = s2;
        sort(sorted_s1.begin(), sorted_s1.end());
        sort(sorted_s2.begin(), sorted_s2.end());
        if (sorted_s1 != sorted_s2) return dp[key] = false; // Early pruning: if sorted characters are not the same

        int n = s1.size();
        for (int i = 1; i < n; ++i) {
            // Check if the split s1[:i] with s2[:i] and s1[i:] with s2[i:] is a valid scramble
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) {
                return dp[key] = true;
            }
            // Check if the split s1[:i] with s2[n-i:] and s1[i:] with s2[:n-i] is a valid scramble
            if (isScramble(s1.substr(0, i), s2.substr(n - i)) && isScramble(s1.substr(i), s2.substr(0, n - i))) {
                return dp[key] = true;
            }
        }

        return dp[key] = false; // If no valid scramble found, return false
    }
};