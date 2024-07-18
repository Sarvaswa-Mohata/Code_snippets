class Solution {
public:
    int largestArea(vector<int>& v){
        stack<pair<int,int>> st;
        int ans=0;
        for(int i=0;i<v.size();i++){
            int tmp=0;
            while(!st.empty() && st.top().first>=v[i]){
                tmp+=st.top().second;
                ans = max(ans, st.top().first*tmp);
                st.pop();
            }
            st.push({v[i], tmp+1});
        }
        int tmp2=0;
        while(!st.empty()){
            tmp2+=st.top().second;
            ans = max(ans, tmp2*st.top().first);
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