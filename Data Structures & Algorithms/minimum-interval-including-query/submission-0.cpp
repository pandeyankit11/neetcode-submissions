class Solution {
   public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end(),
             [](const auto& a, const auto& b) { return (a[1] - a[0]) < (b[1] - b[0]); });


        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            for(int j=0;j<intervals.size();j++){
                if(queries[i]>=intervals[j][0] && queries[i]<=intervals[j][1]){
                    ans.push_back(intervals[j][1]-intervals[j][0]+1);
                    break;
                }
            }
            if(ans.size()!=i+1){
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
