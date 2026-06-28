class Solution {
public:
    typedef pair<int,int>p;
    typedef pair<int,p>q;
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        priority_queue<q>pq;
        int n=passingFees.size();
        vector<vector<int>>dp(n+1,vector<int>(maxTime+1,INT_MAX));
        unordered_map<int,vector<pair<int,int>>>mp;
        for(vector<int>&x:edges){
            mp[x[0]].push_back({x[1],x[2]});
            mp[x[1]].push_back({x[0],x[2]});
        }
        dp[0][0]=passingFees[0];
        pq.push({-1*dp[0][0],{0,0}});
        while(!pq.empty()){
            auto it=pq.top();
            int cost=abs(it.first),time=abs(it.second.first),node=it.second.second;
            if(node==n-1){
                return cost;
            }
            pq.pop();
            for(auto x:mp[node]){
              int nnode=x.first,ncost=cost+passingFees[nnode],ntime=time+x.second;
              if(ntime<=maxTime&&dp[nnode][ntime]>ncost){
                dp[nnode][ntime]=ncost;
                pq.push({-1*ncost,{-1*ntime,nnode}});
              }
            }
        }
        return -1;
    }
};