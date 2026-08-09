class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(),prices.end(),greater<int>()),sort(discounts.begin(),discounts.end(),greater<int>());
        double ans=0;
        for(int i=0;i<prices.size();i++){
           if(i<discounts.size()){
            double p=prices[i],d=discounts[i];
            ans+=(p * (100 - d)) / 100;
           }else{
            double p=prices[i];
            ans+=p;
           }
        }
        return ans;
    }
};