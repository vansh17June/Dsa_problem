class Solution {
public:
    int t[2005][2005];
    bool solve(int i,int j,string& s,string& p){
         if(t[i][j]!=-1){
            return t[i][j];
        }
        if(i>=s.size()&&j>=p.size()){
            return t[i][j]=true;
        }else if(i>=s.size()){
            for(int k=j;k<p.size();k++){
                if(p[k]!='*'){
                    return t[i][j]=false;
                }
            }
            return t[i][j]=true;
        }else if(j>=p.size()){
            return t[i][j]=false;
        }
        if(p[j]>='a'&&p[j]<='z'&&p[j]!=s[i]){
            return t[i][j]=false;
        }
       
        if(p[j]=='*'){
            return t[i][j]=solve(i+1,j,s,p)||solve(i,j+1,s,p);
        }
        return t[i][j]=solve(i+1,j+1,s,p);
        
    }
    bool isMatch(string s, string p) {
        memset(t,-1,sizeof(t));
        return solve(0,0,s,p);
    }
};