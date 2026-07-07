class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n=s.size(),m=t.size();
        if(m<n){
            return false;
        }
        vector<int>pref(n,m),suffix(n,-1);
        int j=0;
        for(int i=0;i<n;i++){
            if(j>=m){
                break;
            }
            if(s[i]!=t[j]){
                while(j<m&&s[i]!=t[j]){
                    j++;
                }
            }
            if(j<m){
              pref[i]=j;
            }else{
                break;
            }
            j++;
        }
        j=m-1;
         for(int i=n-1;i>=0;i--){
            if(j<0){
                break;
            }
            if(s[i]!=t[j]){
                while(j>=0&&s[i]!=t[j]){
                    j--;
                }
            }
            if(j>=0){
              suffix[i]=j;
            }else{
                break;
            }
            j--;
        }
        for(int i=0;i<n;i++){
          int left=i-1>=0?pref[i-1]:-1,right=i+1<n?suffix[i+1]:m;
          if(left!=m&&right!=-1&&right-left>=2){
            return true;
          }
        }
        return false;
    }
};
