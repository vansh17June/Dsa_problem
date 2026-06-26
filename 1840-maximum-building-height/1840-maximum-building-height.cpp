class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restriction) {
        int s = restriction.size();
         if(s==0){
            
            return n-1;
        }
        restriction.push_back({1, 0});
        s++;
        sort(restriction.begin(), restriction.end());
        
       
        if (restriction[s - 1][0] != n) {
            restriction.push_back({n, n - 1});
            s++;
        }
        for (int i = 0; i < restriction.size(); i++) {
            int bn = restriction[i][0], bh = min(restriction[i][1], bn - 1);
            restriction[i][1] = bh;
        }
        
        for (int i = 0; i < s - 1; i++) {
            int cbn = restriction[i][0], cbh = restriction[i][1],
                nbn = restriction[i + 1][0], nbh = restriction[i + 1][1];
             
                    restriction[i + 1][1] =min(nbh,cbh + abs(nbn - cbn));
                
            
        }
        for (int i = s - 1; i > 0; i--) {
            int cbn = restriction[i][0], cbh = restriction[i][1],
                nbn = restriction[i - 1][0], nbh = restriction[i - 1][1];
       
                    restriction[i - 1][1] = min(nbh,cbh + abs(nbn - cbn));
                
            
        }
        int ans = 0;
        for (int i = 0; i <s - 1; i++) {
            int cbn = restriction[i][0], cbh = restriction[i][1],
                nbn = restriction[i + 1][0], nbh = restriction[i + 1][1];
            int d = nbn - cbn;
            ans = max(ans, cbh + (((nbh - cbh) + d) / 2));
        }
        return ans;
    }
};