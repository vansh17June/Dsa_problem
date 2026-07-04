class Solution {
public:
    typedef long long ll;
    ll mod=1e9+7;
    ll dp[101][101][101];
    ll solve(int i,int j,int k,string& word1, string& word2, string& target){
        if(k==target.size()){
            return (i>0&&j>0)?1:0;
        }
        ll ans=0;
        if(dp[i][j][k]!=-1){
            return dp[i][j][k];
        }
        for(int l=i;l<word1.size();l++){
            if(word1[l]==target[k]){
              ans+=solve(l+1,j,k+1,word1,word2,target)%mod;
            }
        }
         for(int l=j;l<word2.size();l++){
            if(word2[l]==target[k]){
              ans+=solve(i,l+1,k+1,word1,word2,target)%mod;
            }
        }
        return dp[i][j][k]=ans%mod;
    }
    int interleaveCharacters(string word1, string word2, string target) {
        memset(dp,-1,sizeof(dp));
        return (int) solve(0,0,0,word1,word2,target);
    }
};