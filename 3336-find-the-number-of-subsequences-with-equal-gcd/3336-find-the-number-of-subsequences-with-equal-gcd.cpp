class Solution {
public:
    long long mod=1e9+7;
    long long dp[202][202][201];
    long long solve(int x,int y,int& n,vector<int>& nums,int i){
        if(i==n){
            if(x==y&&x!=201){
                return 1;
            }
            return 0;
        }
        if(dp[x][y][i]!=-1) return dp[x][y][i];
        long long opt1=(x==201)?solve(nums[i],y,n,nums,i+1):solve(__gcd(x,nums[i]),y,n,nums,i+1);
        long long opt2=(y==201)?solve(x,nums[i],n,nums,i+1):solve(x,__gcd(y,nums[i]),n,nums,i+1);
        long long opt3=solve(x,y,n,nums,i+1);
       
        return dp[x][y][i]=((opt1+opt2)%mod+opt3)%mod;
        
    }
    int subsequencePairCount(vector<int>& nums) {
        int n=nums.size();
       memset(dp, -1, sizeof(dp));
        return (int) solve(201,201,n,nums,0);
    }
};