class Solution {
public:
    string longestPalindrome(string s) {
        string t;
        t+='@';
        for(char c:s){
           t+='#';
           t+=c;
        }
        t+='#';
        t+='&';
        int n=t.size();
        vector<int>v(n,0);
        int center=0,right=0;
        for(int i=1;i<n-1;i++){
            int mirror=2*center-i;
            if(right>i){
                v[i]=min(v[mirror],right-i);
            }
            while(t[i+v[i]+1]==t[i-v[i]-1]){
                v[i]++;
            }
            if(v[i]+i>right){
                center=i;
                right=v[i]+i;
            }
        }
        int idx=-1,len=0;
        for(int i=1;i<n-1;i++){
            int L=i-v[i],R=i+v[i];
            int left=(L-1)/2,right=(R-3)/2;
            if(left>=0&&right>=left&&len<right-left+1){
                idx=left;
                len=right-left+1;
            }
        }
        return s.substr(idx,len);

    }
};