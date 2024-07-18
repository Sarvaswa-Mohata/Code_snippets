class Solution {
public:
int largestArea(vector<int>& heights) {
    stack<pair<int, int>> st; // Stack to store pairs of (height, width)
    int ans = 0; // Initialize answer to 0 (since areas cannot be negative)

    for (int i = 0; i < heights.size(); i++) {
        int width = 0;
        while (!st.empty() && st.top().first >= heights[i]) {
            width += st.top().second; // Accumulate the width
            ans = max(ans, st.top().first * width); // Calculate area with top height
            st.pop();
        }
        st.push({heights[i], width + 1}); // Push current height with accumulated width + 1
    }

    int accumulatedWidth = 0;
    while (!st.empty()) {
        accumulatedWidth += st.top().second; // Accumulate the width
        ans = max(ans, st.top().first * accumulatedWidth); // Calculate area with top height
        st.pop();
    }

    return ans;
}
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans=INT_MIN;
        vector<int> tmp;
        for(int i=0;i<matrix.size();i++){
            vector<int> v;
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]=='1'){
                    v.push_back(1+(i>0 ? tmp[j] : 0));
                }
                else{
                    v.push_back(0);
                }
            }
            tmp=v;
            auto it = largestArea(v);
            cout<<endl;
            ans = max(ans, it);
        }
        return ans;
    }
};