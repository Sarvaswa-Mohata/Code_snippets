class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> v;
        int A = INT_MIN;
        for(int i=0;i<n-2;i++){
            if(nums[i]==A){continue;}
            A=nums[i];
            int k=n-1;
            int j=i+1;
            int a=INT_MIN, b=INT_MIN;
            while(j<k){
                if(a==nums[k]){k--;continue;}
                if(b==nums[j]){j++;continue;}
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==0){
                    v.push_back({nums[i],nums[j],nums[k]});
                    a=nums[k];
                    b=nums[j];
                    j++;
                    k--;
                }
                else{
                    if(sum>0){
                        a=nums[k];
                        k--;
                    }
                    else{
                        b=nums[j];
                        j++;
                    }
                }
            }
        }
        return v;
    }
};