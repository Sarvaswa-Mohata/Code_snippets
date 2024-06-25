class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        vector<int> ans(n,0);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                ans[i]=-1;
                st.push(arr[i]);
            }
            else{
                ans[i]=st.top();
                while(st.size()!=0 && arr[i]>st.top()){
                    st.pop();
                }
                if(st.empty()){
                    st.push(arr[i]);
                }
            }
        }
        return ans;
    }
};