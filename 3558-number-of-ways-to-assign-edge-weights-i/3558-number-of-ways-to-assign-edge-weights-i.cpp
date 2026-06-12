class Solution {
public:
    typedef long long ll;
    ll mod=1e9+7;
    long long power(int d){
        if(d==0){
            return 1;
        }
        long long result=1;
        result*=power(d/2);
        result*=result;
        if(d%2){
            result*=2;
        }
        result%=mod;
        return result;
    }
    int getDepth(unordered_map<int,vector<int>>&mp,int src,int parent){
        int depth=0;
        for(int nbr:mp[src]){
            if(nbr!=parent){
               depth=max(depth,1+getDepth(mp,nbr,src));
            }
        }
        return depth;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<edges.size();i++){
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
        }
        int d=getDepth(mp,1,-1);
        int ans=(int)power(d-1);
        return ans;
    }
};