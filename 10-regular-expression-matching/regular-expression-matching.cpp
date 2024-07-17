class Solution {
public:
    bool helper(int ind1, int ind2, string& s, string& p, int n, int m){
        if(ind1>=n){
            for(int i=ind2;i<m;i++){
                if(p[i]=='*' || p[i+1]=='*') continue;
                return false;
            }
            return true;
        }
        if(ind2>=m){
            if(ind1>=n) return true;
            return false;
        }
        if(p[ind2]!='.' && p[ind2]!='*'){
            if(s[ind1]!=p[ind2] && (ind2+1==m || p[ind2+1]!='*')){
                return false;
            }
            if(p[ind2+1]=='*')
            return helper(ind1, ind2+1, s, p, n, m);
            return helper(ind1+1, ind2+1, s, p, n, m);
        }
        if(p[ind2]=='.'){
            if(ind2+1<m && p[ind2+1]=='*'){
                return helper(ind1, ind2+1, s, p, n, m);
            }
            return helper(ind1+1, ind2+1, s, p, n, m);
        }
        if(p[ind2]=='*'){
            bool ans = false;
            ans|= helper(ind1, ind2+1, s, p, n, m); //matching 0 chars
            if(p[ind2-1]=='.'){
                while(ind1<n){
                    ans|=helper(ind1+1, ind2+1, s, p, n, m);
                    ind1++;
                }
            }
            else{
                auto it = p[ind2-1];
                while(ind1<n && s[ind1]==it){
                    ind1++;
                    ans|=helper(ind1, ind2+1, s, p, n, m); //matching 1 or more chars
                }
            }
            return ans;
        }
        return true;
    }
    bool isMatch(string s, string p) {
        return helper(0,0,s,p,s.size(),p.size());
    }
};