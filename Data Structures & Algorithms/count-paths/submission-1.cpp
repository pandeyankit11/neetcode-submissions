class Solution {
public:

    long long solve(int row,int col,int n,int m,vector<vector<long long>>&dp){

        if(row==n-1 && col==m-1)
        return 1;
        if(row>=n || col>=m)
        return 0;

        if(dp[row][col]!=-1) return dp[row][col];
        int left=solve(row+1,col,n,m,dp);
        int right=solve(row,col+1,n,m,dp);

        return dp[row][col]=left+right;

    }
    int uniquePaths(int m, int n) {
        vector<vector<long long>>dp(n,vector<long long>(m,-1));

        return solve(0,0,n,m,dp);
    }
};
