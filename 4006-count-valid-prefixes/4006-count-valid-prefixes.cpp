class Solution {
public:
    int countValidPrefixes(string s) {
        int ans=0;
        int c0=0,c1=0;
        for(char c:s){
          if(c=='0') c0++;
          if(c=='1') c1++;
          if(abs(c0-c1)<=1) ans++;
        }
        return ans;
    }
};