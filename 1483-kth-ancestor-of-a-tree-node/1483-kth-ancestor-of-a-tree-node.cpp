class TreeAncestor {
public:
    int rows,col;
    vector<vector<int>>up;
    TreeAncestor(int n, vector<int>& parent) {
        rows=n,col=log2(n)+1;
        up.resize(rows,vector<int>(col,-1));
        for(int i=0;i<n;i++){
          up[i][0]=parent[i];
        }
        for(int j=1;j<col;j++){
            for(int i=0;i<n;i++){
                if(up[i][j-1]!=-1){
                    up[i][j]=up[up[i][j-1]][j-1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
       
        for(int i=0;i<col;i++){
            if(k&(1<<i)){
              node=up[node][i];
              if(node==-1){
                return node;
              }
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */