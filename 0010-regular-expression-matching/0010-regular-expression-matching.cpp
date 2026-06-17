class Solution {
public:
    int t[25][25];
    bool solve(int i,int j,string& s,string& p){
        if(i==s.size()&&j==p.size()){
            return true;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        if(i == s.size()) {
    while(j + 1 < p.size() && p[j + 1] == '*')
        j += 2;
    return j == p.size();
}
        if(j==p.size()){
            return false;
        }
        bool x=(s[i]==p[j]||p[j]=='.')?true:false;
        bool case1=false,case2=false,case3=false;
        if((j+1<p.size())&&p[j+1]=='*'){
            case1=x&&solve(i+1,j,s,p);
             case2=solve(i,j+2,s,p);
            
        }
         case3= x&&solve(i+1,j+1,s,p);
         return t[i][j]=case1||case2||case3;
    }
    bool isMatch(string s, string p) {
        memset(t,-1,sizeof(t));
        return solve(0,0,s,p);
    }
};