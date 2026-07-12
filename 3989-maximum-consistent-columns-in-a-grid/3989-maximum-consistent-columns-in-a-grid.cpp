class Solution {
public:
    int dp[255][255];
    bool check(vector<vector<int>>& grid, int& limit,int curr,int prev){
        int m=grid.size();
        for(int i=0;i<m;i++){
             if(abs(grid[i][prev]-grid[i][curr])>limit){
                return false;
             }
        }
        return true;
    }
    int solve(vector<vector<int>>& grid, int& limit,int curr,int prev,int& n){
         if(curr==n){
            return 0;
         }
         if(prev!=-1&&dp[curr][prev]!=-1){
            return dp[curr][prev];
         }
         int take=INT_MAX,skip=INT_MAX;
         if(prev==-1||check(grid,limit,curr,prev)){
            take=solve(grid,limit,curr+1,curr,n);
         }
         skip=1+solve(grid,limit,curr+1,prev,n);
         if(prev!=-1){
          dp[curr][prev]=min(take,skip);  
         }
         return min(take,skip);
    }
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        int n=grid[0].size();
        memset(dp,-1,sizeof(dp));
        int ans=n-solve(grid,limit,0,-1,n);
        return ans;
    }
};


