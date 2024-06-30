class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> v;
        for(int i=1;i<=min(n,target[target.size()-1]);i++){
            if(find(target.begin(),target.end(),i)!=target.end()){
                v.push_back("Push");
            }
            else{
                v.push_back("Push");
                v.push_back("Pop");
            }   
        }
        return v;
    }
};