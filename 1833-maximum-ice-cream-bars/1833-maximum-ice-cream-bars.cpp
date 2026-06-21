class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int ans=0,i=0;
        while(i<costs.size()&&coins>0){
            if(coins>=costs[i]){
                ans++;
            }
            coins-=costs[i];
            i++;
        }
        return ans;
    }
};