class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int ans=0;
        for(auto it:s){
            if(s.find(it-1)==s.end()){
                int cnt=1;
                int smaller=it;
                while(s.find(smaller+1)!=s.end()){
                    smaller++;
                    cnt++;
                }
                ans = max(ans,cnt);
            }
        }
        return ans;
    }
};