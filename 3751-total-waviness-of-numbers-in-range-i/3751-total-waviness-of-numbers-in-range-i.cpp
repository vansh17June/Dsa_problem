class Solution {
public:
    long long dp[10][10][16][2][16][2];
    long long solve(int fp,int sp,int i,int temp,string& s,int count,int fnz){
        if(i==s.size()){
            return count;
        }
        int end=(temp==1)?s[i]-'0':9;
        long long ans=0;

        if(fnz==1&&sp!=-1&&dp[fp][sp][i][temp][count][fnz]!=-1){
           return dp[fp][sp][i][temp][count][fnz];
        }
        for(int j=0;j<=end;j++){
         int updatedcount = count +
                   (
                     ((sp!=-1) &&(fnz==1)&&
                     ((fp>sp && fp>j) || (fp<j && fp<sp)))
                     ? 1 : 0
                   );
          ans+=solve((fnz==0&&j==0)?-1:j,fp,i+1,(temp==1 && j==end)?1:0,s,updatedcount,(fnz||j!=0));
        }
        if(sp!=-1&&fnz==1){
            dp[fp][sp][i][temp][count][fnz]=ans;
        }
        return ans;
    }
    long long totalWaviness(long long num1, long long num2) {
      if(num2<=100){
        return 0;
      }
      int fp=-1,sp=-1,tight=1,i=0,fnz=0;
      num1=max(num1,1ll*101);
      string s=to_string(num1-1);
      memset(dp,-1,sizeof(dp));
      long long left=solve(fp,sp,i,tight,s,0,fnz);
      
      s=to_string(num2);
      memset(dp,-1,sizeof(dp));
      long long right=solve(fp,sp,i,tight,s,0,fnz);
      return right-left;
    }
};