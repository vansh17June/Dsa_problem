class Solution {
public:
    unordered_map<int,vector<pair<int,int>>>mp;
    typedef long long ll;
    typedef pair<ll,int> P;

    bool check(int x,long long k,int n){
        vector<ll>v(n,LLONG_MAX);
        priority_queue<P> pq;
        pq.push({0,0});
        v[0]=0;
        while(!pq.empty()){
            ll cost=abs(pq.top().first);
            int node=pq.top().second;
            pq.pop();
            if(v[node]<cost){
                continue;
            }
            if(node==n-1&&cost<=k){
                return true;
            }
            for(auto it:mp[node]){
               if(v[it.first]>cost+it.second&&it.second>=x&&cost+it.second<=k){
                pq.push({-1*(cost+it.second),it.first});
                v[it.first]=cost+it.second;
               }
            }
        }
        return false;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k){ 
      int start=INT_MAX,end=INT_MIN;
      int n=online.size();
      for(vector<int>&x:edges){
        int node1=x[0],node2=x[1],cost=x[2];
        if(online[node1]==false||online[node2]==false){
            continue;
        }
        start=min(start,cost),end=max(end,cost);
        mp[x[0]].push_back({x[1],x[2]});
      }
      int ans=-1;
      while(start<=end){
        int mid=start+(end-start)/2;
        if(check(mid,k,n)){
            ans=mid;
            start=mid+1;
        }else{
            end=mid-1;
        }
      }
      return ans;

    }
};