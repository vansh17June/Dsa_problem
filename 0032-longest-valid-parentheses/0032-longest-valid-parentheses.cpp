class Solution {
public:
    vector<int>dp;
    void solve(int i,string &s){
        if(i<0){
            return ;
        }
        if(s[i]==')'){
            solve(i-1,s);
            return;
        }
        int case1=0,case2=0;
        if(i+1<s.size()&&s[i+1]==')'){
            case1=2+((i+2<s.size())?dp[i+2]:0);
            dp[i]=case1;
        }
        if(i+1<s.size()&&s[i+1]=='('){
            case2=i+1<s.size()?dp[i+1]:0;
            if(i+case2+1<s.size()&&s[i+case2+1]==')'){
                dp[i]=case2+2+((i+case2+2<s.size())?dp[i+case2+2]:0);
            }
        }
        solve(i-1,s);
    }
    int longestValidParentheses(string s) {
        int n=s.size();
        if(n==0){
            return 0;
        }
        dp.resize(n,0);
        solve(s.size()-1,s);
        int ans=*max_element(dp.begin(),dp.end());
        return ans;
    }
};
