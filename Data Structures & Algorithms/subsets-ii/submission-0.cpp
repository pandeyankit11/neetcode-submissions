class Solution {
public:

    void solve(int i,vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans){
        
            ans.push_back(temp);
         

       for(int j=i;j<nums.size();j++){
        if(j>i && nums[j]==nums[j-1]) continue;

        temp.push_back(nums[j]);
        solve(j+1,nums,temp,ans);
        temp.pop_back();
       }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        vector<int>temp;

        solve(0,nums,temp,ans);
        return ans;
    }
};
