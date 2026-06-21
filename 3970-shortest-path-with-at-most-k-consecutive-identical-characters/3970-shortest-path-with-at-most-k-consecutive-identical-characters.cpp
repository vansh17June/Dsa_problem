class Solution {
public:
    typedef pair<int, pair<int,int>> p;
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        queue<p> pq;
        unordered_map<int,vector< pair<int, int>>> mp;
        for (vector<int>& x : edges) {
            mp[x[0]].push_back({x[1], x[2]});
        }
        vector<vector<int>> temp(n, vector<int>(k + 1, INT_MAX));
        pq.push({0, {0, 1}});
        temp[0][1] = 0;
        while (!pq.empty()) {
            int n = pq.size();
            for (int i = 0; i < n; i++) {
                auto it = pq.front();
                int node = it.first, cost =it.second.first,
                    rep = it.second.second;
                pq.pop();
                for (auto l:mp[node]){
                    int nnode=l.first,ncost=l.second,nrep=rep;
                    if(labels[node]==labels[nnode]){
                        nrep++;
                    }else{
                        nrep=1;
                    }
                    if(nrep<=k&&temp[nnode][nrep]>cost+ncost){
                        temp[nnode][nrep]=cost+ncost;
                        pq.push({nnode,{cost+ncost,nrep}});
                    }
                }
            }
        }
        int ans=INT_MAX;
        for(int i=1;i<=k;i++){
           ans=min(ans,temp[n-1][i]);
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};