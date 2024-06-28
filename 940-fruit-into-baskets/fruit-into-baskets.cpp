class Solution {
public:
    int totalFruit(vector<int>& nums) {
        map<int,int> mp;
        int l=0, r=0, ans=0, tmp=0;
        int n=nums.size();
        while(r<n){
            mp[nums[r]]++;
            tmp++;
            while(mp.size()>2){
                mp[nums[l]]--;
                if(mp[nums[l]]==0){mp.erase(nums[l]);}
                l++;
                tmp--;
            }
            ans = max(ans,tmp);
            r++;
        }   
        return ans;
    }
};