class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        
        vector<int> prev(m + 1, 0);
        prev[m] = 1; // Base case: an empty pattern matches an empty string
        
        // Initialize for cases where the pattern contains only '*' characters
        for (int j = m - 1; j >= 0; j--) {
            if (p[j] == '*') prev[j] = prev[j + 1];
            else break;
        }
        
        for (int i = n - 1; i >= 0; i--) {
            vector<int> curr(m + 1, 0);
            for (int j = m - 1; j >= 0; j--) {
                if (p[j] == '*') {
                    curr[j] = curr[j + 1] || prev[j]; // '*' can match empty or any sequence
                } else if (p[j] == '?' || p[j] == s[i]) {
                    curr[j] = prev[j + 1]; // Match one character or '?'
                } else {
                    curr[j] = 0; // No match
                }
            }
            prev = curr;
        }
        
        return prev[0];
    }
};
