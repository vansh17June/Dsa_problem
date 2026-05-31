class Solution {
public:
   vector<vector<int>>dp;
   int solve(vector<vector<int>>& items, int budget,int i,int& price,vector<int>&temp){
    if(i>=items.size()){
        return budget/price;
    }
    int take=0,skip=0;
    if(dp[i][budget]!=-1){
        return dp[i][budget];
    }
    skip=solve(items,budget,i+1,price,temp);
    if(items[i][1]<=budget){
        take=1+temp[i]+solve(items,budget-items[i][1],i+1,price,temp);
    }
    return dp[i][budget]=max(take,skip);
   }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int ans=0;
        int n=items.size();
        vector<int>temp(n,0);
        int price=INT_MAX;
        for(int i=0;i<n;i++){
            price=min(price,items[i][1]);
            for(int j=0;j<n;j++){
                if(i==j){
                    continue;
                }
                if(items[j][0]%items[i][0]==0){
                    temp[i]++;
                }     
            }
        }
        dp.resize(1001,vector<int>(1501,-1));
        ans=solve(items,budget,0,price,temp);
        return ans;      
    }
};