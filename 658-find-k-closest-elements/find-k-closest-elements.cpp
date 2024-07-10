class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        vector<int> v;
        int tmp = min(k,mp[x]);
        k-=tmp;
        while(tmp--){
            v.push_back(x);
        }
        for(int i=1;i<=20001;i++){
            tmp = min(mp[x-i],k);
            k-=tmp;
            while(tmp--){
                v.push_back(x-i);
            }
            tmp = min(mp[x+i],k);
            k-=tmp;
            while(tmp--){
                v.push_back(x+i);
            }
        }
        sort(v.begin(),v.end());
        return v;
    }
};