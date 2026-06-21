class Solution {
public:
   typedef pair<int,int> p;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>>mp;
        for(vector<int>&x:flights){
            mp[x[0]].push_back({x[1],x[2]});
        }
        queue<p>pq;
        int t=0;
        vector<int>temp(n,INT_MAX);
        pq.push({0,src});
        temp[src]=0;
        while(!pq.empty()&&t<=k){
          int n=pq.size();
          for(int i=0;i<n;i++){
            auto it=pq.front();
            pq.pop();
            int node=it.second,cost=it.first;
            for(p y:mp[node]){
                if(temp[y.first]>y.second+cost){
                   temp[y.first]=y.second+cost;
                    pq.push({y.second+cost,y.first});
                }
            }
          }
          t++;
        }
        if(temp[dst]==INT_MAX){
            return -1;
        }
        return temp[dst];
    }
};