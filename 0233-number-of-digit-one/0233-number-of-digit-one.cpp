class Solution {
public:
    int dp[11][11][11];
    int solve(int count,int i,int tight,string& s){
        if(i==s.size()){
            return count;
        }
        int end=(tight==1)?(s[i]-'0'):9;
        if(dp[i][tight][count]!=-1){
            return dp[i][tight][count];
        }
        int ans=0;
        for(int j=0;j<=end;j++){
            int updatedcount=count+(j==1?1:0);
           ans+= solve(updatedcount,i+1,(tight==0||j<end)?0:1,s);
        }
       return dp[i][tight][count]=ans;
    }
    int countDigitOne(int n) {
        string s=to_string(n);
        memset(dp,-1,sizeof(dp));
        return solve(0,0,1,s);
    }
};