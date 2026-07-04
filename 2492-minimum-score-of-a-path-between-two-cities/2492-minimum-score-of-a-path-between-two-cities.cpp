class Solution {
public:
    vector<bool>vis;
    int nodes;
    int ans=INT_MAX;
    void dfs(int src,unordered_map<int,vector<pair<int,int>>>&mp){
        vis[src]=true;
        for(auto it:mp[src]){
            int idx=it.first;
            ans=min(ans,it.second);
            if(vis[idx]==false){
                    dfs(idx,mp);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>>mp;
        for(vector<int>& x:roads){
            mp[x[0]].push_back({x[1],x[2]});
            mp[x[1]].push_back({x[0],x[2]});
        }
        vis.resize(n+1,false);
        nodes=n;
        dfs(1,mp);
        return ans;
    }
};