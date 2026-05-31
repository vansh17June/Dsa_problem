class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int ans=0,n=items.size(),price=INT_MAX;
        vector<int>temp(1e5+2,0);
        for(int i=0;i<n;i++){
          price=min(price,items[i][1]);
          temp[items[i][0]]++;
        }
        for(int i=1;i<temp.size();i++){
            for(int j=2*i;j<temp.size();j+=i){
                temp[i]+=temp[j];
            }
        }
        vector<pair<int,int>>v;
        for(int i=0;i<items.size();i++){
            if(temp[items[i][0]]-1>0){
            v.push_back({items[i][1],temp[items[i][0]]-1});
            }
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            int x=v[i].first,y=v[i].second;
            if(price*2<=x){
                break;
            }
            int times=min(y,budget/x);
            budget-=x*times;
            ans+=2*times;
        }
        ans+=(budget/price);

        return ans;
    }
};