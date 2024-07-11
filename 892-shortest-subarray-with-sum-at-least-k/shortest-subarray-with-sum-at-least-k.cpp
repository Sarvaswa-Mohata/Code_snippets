class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefixSum(n + 1, 0);

        // Calculate prefix sums
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        deque<int> dq;
        int ans = INT_MAX;

        for (int i = 0; i < prefixSum.size(); ++i) {
            // Ensure the deque maintains elements in increasing order of prefix sums
            while (!dq.empty() && prefixSum[i] - prefixSum[dq.front()] >= k) {
                ans = min(ans, i - dq.front());
                dq.pop_front();
            }

            // Maintain increasing order of prefix sums in the deque
            while (!dq.empty() && prefixSum[i] <= prefixSum[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
