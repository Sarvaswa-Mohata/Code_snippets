class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> v;
        int ff=intervals[0][0], ss=intervals[0][1];

        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=ss){
                ss=max(ss,intervals[i][1]);
            }
            else{
                v.push_back({ff,ss});
                ff=intervals[i][0];
                ss=intervals[i][1];
            }
        }
        v.push_back({ff,ss});
        return v;
    }
};