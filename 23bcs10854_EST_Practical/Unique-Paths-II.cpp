class Solution {
public:
    int func(int i,int j,vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0 ) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int top=0,left=0;
        if(i>0 && obstacleGrid[i-1][j]!=1) top=func(i-1,j,obstacleGrid,dp);
        if(j>0 && obstacleGrid[i][j-1]!=1) left=func(i,j-1,obstacleGrid,dp);
        return dp[i][j]=top+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1]==1) return 0;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return func(m-1,n-1,obstacleGrid,dp);
        // for(int i=0;i<m;i++){

        //     for(int j=0;j<n;j++){
        //         if(i==0 && j==0) dp[i][j]=1;
        //         else{
        //             int top=0,left=0;
        //             if(i>0 && obstacleGrid[i-1][j]!=1) top=dp[i-1][j];
        //             if(j>0 && obstacleGrid[i][j-1]!=1) left=dp[i][j-1];
        //             dp[i][j]=top+left;
        //         }
                
        //     }
        // }
        // return dp[m-1][n-1];
        // vector<int> prev(n,0);
        // // return func(m-1,n-1,obstacleGrid,dp);
        // for(int i=0;i<m;i++){
        //     vector<int> temp(n,0);
        //     for(int j=0;j<n;j++){
        //         if(i==0 && j==0) temp[j]=1;
        //         else{
        //             int top=0,left=0;
        //             if(i>0 && obstacleGrid[i-1][j]!=1) top=prev[j];
        //             if(j>0 && obstacleGrid[i][j-1]!=1) left=temp[j-1];
        //             temp[j]=top+left;
        //         }
        //     }
        //     prev=temp;
        // }
        // return prev[n-1];
    }
};