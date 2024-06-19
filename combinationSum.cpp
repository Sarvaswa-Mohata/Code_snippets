#include<bits/stdc++.h>
using namespace std;

void helper(int ind, int target, vector<int>& candidates, vector<vector<int>>& ans, vector<int>& ds){
    
    //base case :
    if(ind == candidates.size()){
        if(target==0){
            ans.push_back(ds);
        }   
        return;
    }

    //pick:
    if(target>=candidates[ind]){
        ds.push_back(candidates[ind]);
        helper(ind, target-candidates[ind], candidates, ans, ds);
        ds.pop_back();
    }
    //don't pick :
    helper(ind+1, target, candidates, ans, ds);
    return;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> candidates;
        for(int i=0;i<n;i++){
            int ele;
            cin>>ele;
            candidates.push_back(ele);
        }
        int target;
        cin>>target;
        vector<int> ds;
        vector<vector<int>> ans;
        helper(0,target, candidates, ans, ds);
        for(int i=0;i<ans.size();i++){
            cout<<"(";
            for(int j=0;j<ans[i].size();j++){
                cout<<ans[i][j];
                if(j!=ans[i].size()-1)
                cout<<",";
            }
            cout<<")";
            if(i!=ans.size()-1)
            cout<<",";
        }
        cout<<endl;
    }
}