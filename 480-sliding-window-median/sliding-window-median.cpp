class Solution {
public:
    void balance_heaps(multiset<double>& max_heap, multiset<double>& min_heap) {
        while (max_heap.size() > min_heap.size() + 1) {
            min_heap.insert(*max_heap.rbegin());
            max_heap.erase(--max_heap.end());
        }
        while (min_heap.size() > max_heap.size()) {
            max_heap.insert(*min_heap.begin());
            min_heap.erase(min_heap.begin());
        }
    }

    void add_num(multiset<double>& max_heap, multiset<double>& min_heap, double num) {
        if (max_heap.empty() || num <= *max_heap.rbegin()) {
            max_heap.insert(num);
        } else {
            min_heap.insert(num);
        }
        balance_heaps(max_heap, min_heap);
    }

    void remove_num(multiset<double>& max_heap, multiset<double>& min_heap, double num) {
        if (num <= *max_heap.rbegin()) {
            max_heap.erase(max_heap.find(num));
        } else {
            min_heap.erase(min_heap.find(num));
        }
        balance_heaps(max_heap, min_heap);
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<double> max_heap, min_heap;
        vector<double> ans;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            add_num(max_heap, min_heap, nums[i]);

            if (i >= k - 1) {
                if (max_heap.size() == min_heap.size()) {
                    ans.push_back((static_cast<double>(*max_heap.rbegin()) + *min_heap.begin()) / 2.0);
                } else {
                    ans.push_back(static_cast<double>(*max_heap.rbegin()));
                }

                remove_num(max_heap, min_heap, nums[i - k + 1]);
            }
        }

        return ans;
    }
};