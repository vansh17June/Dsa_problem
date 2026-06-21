class Solution {
public:
    long long dp[20][2][2][10];
    long long solve(int i,int n,string& s,int limit,int leading_zero,int prev,int& k){
        if(i==n){
            return !leading_zero;
        }
        int end=limit?s[i]-'0':9;
        long long a;
        if(prev!=-1)
         a=dp[i][limit][leading_zero][prev];
        if(prev!=-1&&a!=-1){
            return a;
        }
        long long ans=0;
        for(int start=0;start<=end;start++){
            int ntight=limit&&(start==end);
            if(leading_zero==1&&start==0){
                ans+=solve(i+1,n,s,ntight,1,-1,k);
            }else{
                if(prev==-1){
                    ans+=solve(i+1,n,s,ntight,0,start,k);
                }else if(abs(start-prev)<=k){
                   ans+=solve(i+1,n,s,ntight,0,start,k);
                }
            }
        }
        if(prev!=-1)
        dp[i][limit][leading_zero][prev]=ans;
        return ans;
    }
    long long goodIntegers(long long l, long long r, int k) {
        string s1=to_string(r);
        memset(dp,-1,sizeof(dp));
        int n=s1.size();
        long long val1=solve(0,n,s1,1,1,-1,k);
        string s2=to_string(l-1);
        memset(dp,-1,sizeof(dp));
        n=s2.size();
        long long val2=solve(0,n,s2,1,1,-1,k);
        return abs(val1-val2);
    }
};