class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1, ele2, cnt1=0, cnt2=0;
        int n=nums.size();
        int flg1=0, flg2=0;
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            //either nums[i] has not been assigned to the other one or at least it is not equal
            if(cnt1==0 && (flg2==0 || ele2!=nums[i])){
                flg1=1;
                cnt1=1;
                ele1 = nums[i];
            }
            else if(cnt2==0 && (flg1==0 || ele1!=nums[i])){
                flg2=1;
                cnt2=1;
                ele2=nums[i];
            }
            else if(ele1==nums[i]){
                cnt1++;
            }
            else if(ele2 == nums[i]){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0, cnt2=0;
        for(int i=0;i<nums.size();i++){
            if(flg1!=0 && ele1==nums[i]){
                cnt1++;
            }
            if(flg2!=0 && ele2==nums[i]){
                cnt2++;
            }
        }
        if(cnt1>n/3){
            v.push_back(ele1);
        }
        if(cnt2>n/3){
            v.push_back(ele2);
        }
        return v;
    }
};