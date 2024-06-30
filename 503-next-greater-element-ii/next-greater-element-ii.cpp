class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            nums.push_back(nums[i]);
        }
        vector<int> ans(2*n,-1);
        for(int i=2*n-1;i>=0;i--){
            while(st.size()>0 && nums[i]>=st.top()){
                st.pop();
            }
            if(st.empty()){
                st.push(nums[i]);
            }
            else{
                ans[i] = st.top();
                st.push(nums[i]);
            }
        }
        vector<int> fin_ans;
        for(int i=0;i<n;i++){
            fin_ans.push_back(ans[i]);
        }
        return fin_ans;
    }
};