class Solution {
public:
    char processStr(string s, long long k) {
        long long len=0;
        
        for(char c:s){
            if(c=='*'){
                len=max(0ll,len-1);
            }else if(c=='#'){
                len=2*len;
            }else if(c>='a'&&c<='z'){
                len++;
            }
        }
        cout<<len<<" ";
        if(len<=k){
            return '.';
        }
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]>='a'&&s[i]<='z'){
                len--;
            }else if(s[i]=='*'){
                len++;
            }else if(s[i]=='#'){
                len=len/2;
                 k = (k >= len) ? k - len : k;
            }else{
                k=len-k-1;
            }
            if(k==len){
                return s[i];
            }

        }
        return '.';
    }
};