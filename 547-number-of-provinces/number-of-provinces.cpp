class Solution {
public:
    int findCircleNum(vector<vector<int>>& v) {
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[0].size();j++){
                if(i==j) continue;
                if(v[i][j]==1){
                    mp[i+1].push_back(j+1);
                    mp[j+1].push_back(i+1);
                }
            }
        }
        int n=v.size();
        vector<bool> vis(n+1,false);
        queue<int> q;
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(vis[i]) continue;
            vis[i]=true;
            q.push(i);
            while(q.size()!=0){
                auto jt = q.front();
                for(auto it:mp[jt]){
                    if(vis[it])
                    continue;
                    vis[it]=true;
                    q.push(it);
                }
                q.pop();
            }
            cnt++;
        }
        return cnt;
    }
};