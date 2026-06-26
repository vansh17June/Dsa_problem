class Solution {
public:
    int M=1e9+7;
    vector<int>depth,pow2;
    vector<vector<int>>up;
    unordered_map<int,vector<int>>mp;
    void dfs(int node,int parent){
       up[node][0]=parent;
       if(parent!=-1){
        depth[node]=depth[parent]+1;
       }
       for(int x:mp[node]){
        if(x!=parent){
            dfs(x,node);
        }
       }
    }
    void buildtable(){
        for(int j=1;j<up[0].size();j++){
            for(int i=0;i<up.size();i++){
               if(up[i][j-1]!=-1){
                up[i][j]=up[up[i][j-1]][j-1];
               }
            }
        }
    }
    int lca(int u,int v){
        if(depth[v]>depth[u]){
            swap(u,v);
        }
        int k=depth[u]-depth[v];
        for(int i=0;i<up[0].size();i++){
            if(k&(1<<i)){
              
                u=up[u][i];
            }
        }
        if(u==v){
            return u;
        }
        for(int j=up[0].size()-1;j>=0;j--){
            if(up[u][j]==-1){
                continue;
            }
            if(up[u][j]!=up[v][j]){
                u=up[u][j];
                v=up[v][j];
            }
        }
        return up[u][0];
    }
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int node=edges.size()+1;
        int n=node;
        vector<int>ans;
        depth.resize(n);
        pow2.resize(n);
        up.resize(n,vector<int>(log2(n)+1,-1));
        pow2[0]=1;
        for(int i=1;i<n;i++){
            pow2[i]=(2ll*pow2[i-1])%M;
        }
        for(vector<int>&x:edges){
            int u=x[0]-1,v=x[1]-1;
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        depth[0]=0;
        dfs(0,-1);
        buildtable();
        for(vector<int>&x:queries){
            int u=x[0]-1,v=x[1]-1;
            int d=depth[u]+depth[v]-2*depth[lca(u,v)];
            if(d==0){
                ans.push_back(0);
            }else{
                ans.push_back(pow2[d-1]);
            }
        }
        return ans;
    }
};