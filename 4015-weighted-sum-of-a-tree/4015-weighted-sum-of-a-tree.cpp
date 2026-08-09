class Solution {
public:
    void help(vector<int>& parent, int i, vector<long long>& v) {
        if (v[i] != -1) {
            return;
        }

        if (v[parent[i]] == -1) {
            help(parent, parent[i], v);
        }

        v[i] = 1 + v[parent[i]];
    }
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
       int n=parent.size();
       vector<long long>v(n,-1);
       v[0]=1;
       long long h=1;
       for(int i=1;i<n;i++){
          if(v[i]==-1){
             help(parent,i,v);
          }
          h = max(h, v[i]);
       } 
       long long ans=0;
       for(int i=0;i<n;i++){
        ans+=(1ll*nums[i])*(h-v[i]+1);
       }
       return ans;
    }
};