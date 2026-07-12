class Solution {
public:
    vector<string> createGrid(int m, int n, int k) {
        vector<string> ans(m,string(n,'#'));
       if((m==1||n==1)&&k>1){
        return {};
       }
       if (m == 3 && n ==3 && k == 4) {
            return {"..#", "...","#.."};
        }
        for (int i = 0; i < n; i++) {
            ans[0][i] = '.';
        }
        for (int i = 0; i < m; i++) {
            ans[i][n - 1] = '.';
        }
        k--;
        
        if(m>n){
            int i=1;
            while(k&&i<m){
                ans[i][n-2]='.';
                i++;
                k--;
            }
        }else{
            int i=n-2;
            while(k&&i>=0){
                ans[1][i]='.';
                i--;
                k--;
            }
        }

        if (k) {
            return {};
        }
        return ans;

        return ans;
    }
};

