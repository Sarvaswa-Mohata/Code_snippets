class Solution {
public:
    int minDistance(string w1, string w2) {
        int n=w1.size();
        int m=w2.size();
        vector<int> prev(m+1,0), curr(m+1, 0);
        for(int j=0;j<=m;j++){
            prev[j] = j;
        }
        for(int i=1;i<=n;i++){
            curr[0] = i;
            for(int j=1;j<=m;j++){
                if(w1[i-1] == w2[j-1]){
                    curr[j] = prev[j-1];
                }
                else{
                    curr[j] = min({curr[j-1], prev[j], prev[j-1]})+1;
                }
            }
            prev = curr;
            fill(curr.begin(),curr.end(), 0);
        }
        return prev[m];
    }
};