class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> v;
        if(nums.size()<=3){return v;}
        sort(nums.begin(),nums.end());
        bool flg1=false;
        int a=INT_MIN;
        for(int i=0;i<nums.size()-3;i++){
            if(flg1 && nums[i]==a){continue;}
            flg1=true;
            a=nums[i];
            int b=INT_MIN;
            bool flg2=false;
            for(int j=i+1;j<nums.size()-2;j++){
                if(flg2 && nums[j]==b){continue;}
                flg2=1;
                b=nums[j];
                int c=INT_MIN, d=INT_MIN;
                bool flg3=false, flg4=false;
                int k=j+1, l=nums.size()-1;
                while(k<l){
                    if(flg3 && nums[k]==c){
                        k++;
                        continue;
                    }
                    if(flg4 && nums[l]==d){
                        l--;
                        continue;
                    }
                    long long int sum=nums[i];
                    sum+=nums[j];
                    sum+=nums[k];
                    sum+=nums[l];
                    if(sum>target){
                        flg4=1;
                        d=nums[l];
                        l--;
                    }
                    else if(sum<target){
                        flg3=1;
                        c=nums[k];
                        k++;
                    }
                    else{
                        v.push_back({nums[i],nums[j],nums[k],nums[l]});
                        flg3=1;
                        flg4=1;
                        c=nums[k];
                        d=nums[l];
                        k++;;
                        l--;
                    }
                }
            }
        }
        return v;
    }
};